#include <LiquidCrystal_I2C.h>
#include "cSnake.h"
#include "cMainMenu.h"
#include "cFood.h"
#include "cWorld.h"

const int ScaleLcdHorizontal = 16;                                  //Horizontal LCD screen size
const int ScaleLcdVertical = 2;                                     //Vertical LCD screen size

LiquidCrystal_I2C lcd (0x27, ScaleLcdHorizontal, ScaleLcdVertical);
const LiquidCrystal_I2C *LCD = &lcd;

const int V = 2;
const int H = 1;
bool Active = false;
int vert, horiz;

cWorld World(LCD);
cWorld *world = &World;

cFood Food(LCD, world);
cFood *food = &Food;

cSnake Snake(LCD,world);
cSnake *snake = &Snake;;

cMainMenu *menu;
  
void setup() {
  lcd.begin(); 
  Serial.begin(9600);
  lcd.backlight();
  cMainMenu Menu(LCD,world);
  menu = &Menu;
}

void loop() {  
  vert = analogRead(V);
  horiz = analogRead(H);
  if(Active){
     if(world->Create){
      world->CreateWorld(ScaleLcdHorizontal, ScaleLcdVertical);
      snake->Start();
    }
     if(world->SpawnFood)
      food->GenerateFood();
    snake->MoveSnake(vert,horiz);
    if(world->GameOver){
      world->GameOver=false;
      menu->GameOver();
      Active = false;
      snake->Again();
      }
    }
  if(horiz<=100&&Active==false){
      menu->SetActiveMenu(false);
      Active =true;
  }
  else if(horiz>=980&&Active==false){
      menu->SetActiveMenu(true);
      Active = true; 
  }  
}
