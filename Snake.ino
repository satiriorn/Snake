#include <LiquidCrystal_I2C.h>
#include "cSnake.h"
#include "cMainMenu.h"
#include "cFood.h"
#include "cWorld.h"

const int ScaleLcdHorizontal = 16;                                  //Horizontal LCD screen size
const int ScaleLcdVertical = 2;                                     //Vertical LCD screen size

LiquidCrystal_I2C lcd (0x27, ScaleLcdHorizontal, ScaleLcdVertical);
const LiquidCrystal_I2C *LCD = &lcd;                                //initialization of the pointer to pass to other classes

const int V = 2;
const int H = 1;
bool Active = false;
int vert, horiz;
//init game obj and pointer to them
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
  Activity();//The state in which the player is playing
  ChoiceMode(horiz);//State of player
}

inline void Activity(){
  if(Active){
    if(world->Create){//Creating world if we started first time
      world->CreateWorld(ScaleLcdHorizontal, ScaleLcdVertical);
      snake->Start();
    }
    if(world->SpawnFood)//Creating Food if the snake ate or first time
      food->GenerateFood();
    snake->MoveSnake(vert,horiz);
    GameState();
  }
}
inline void GameState(){
  if(world->Score>=10){//State of victory
    Active = false;
    menu->Win();
    snake->Again();
   }
  if(world->GameOver){//Loss status
    world->GameOver=false;
    menu->GameOver();
    Active = false;
    snake->Again();
   }
}
inline void ChoiceMode(int& h){
    if(horiz<=100&&Active==false){
      menu->SetActiveMenu(false);
      Active =true;
  }
  else if(horiz>=980&&Active==false){
      menu->SetActiveMenu(true);
      Active = true; 
  } 
}
