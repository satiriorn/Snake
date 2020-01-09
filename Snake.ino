#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "cSnake.h"
#include "cMainMenu.h"
#include "cFood.h"

LiquidCrystal_I2C lcd (0x27,16,2);
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
    if(food->SpawnFood){
      food->GenerateFood();
    }
    snake->Start();
    snake->MoveSnake(vert,horiz);
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
