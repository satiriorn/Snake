#include <LiquidCrystal_I2C.h>
#include "cSnake.h"
#include "cMainMenu.h"
#include "cFood.h"

const uint8_t ScaleLcdHorizontal = 16;
const uint8_t ScaleLcdVertical = 2;
LiquidCrystal_I2C lcd (0x27, ScaleLcdHorizontal, ScaleLcdVertical);
const LiquidCrystal_I2C *LCD = &lcd;

const uint8_t V = 1;
const uint8_t H = 0;
bool Active = false;
int16_t vert, horiz;

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
      food->GenerateFood();
      world->CreateWorld(ScaleLcdHorizontal, ScaleLcdVertical);
      snake->Start();
    }
    snake->MoveSnake(vert,horiz);
    if(world->GameOver){
      world->GameOver=false;
      menu->GameOver();
      Active = false;
      }
    }
    ChooseMenu();
}

void ChooseMenu(){
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
