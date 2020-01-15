#include <LiquidCrystal_I2C.h>
#include "cSnake.h"
#include "cMainMenu.h"
#include "cFood.h"

const int ScaleLcdHorizontal = 16;
const int ScaleLcdVertical = 2;
LiquidCrystal_I2C lcd (0x27, ScaleLcdHorizontal, ScaleLcdVertical);
const LiquidCrystal_I2C *LCD = &lcd;

const int V = 1;
const int H = 0;
bool Active = false;
int vert, horiz;

cFood Food(LCD);
cFood *food = &Food;

cWorld World(LCD,food);
cWorld *world = &World;

cSnake Snake(LCD,world);
cSnake *snake = &Snake;;

cMainMenu *menu;
  
void setup() {
  lcd.begin(); 
  Serial.begin(9600);
  lcd.backlight();
  cMainMenu Menu(LCD);
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
    if(food->SpawnFood){
      food->GenerateFood();
    }
    snake->MoveSnake(vert,horiz);
    if(world->GameOver){
      world->GameOver=false;
      menu->GameOver();
      Active = false;
      }
    }
  if(horiz<=100&&Active==false){
        menu->SetActiveMenu(false);
        Active =true;
        snake->Again();
        }
  else if(horiz>=980&&Active==false){
        menu->SetActiveMenu(true);
        Active = true;
        snake->Again();
  }  
}
