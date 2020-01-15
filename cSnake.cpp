#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L, cWorld* W){
  LCD = L;
  World = W;
  VerticalLocation = Time = HorizontalLocation = VertGlobal = 0;
  LongSnake =  1;
  HeadSnake = TailSnake = 4;
 }
 
inline void cSnake::Clear(){
  World->WorldBlocks[HorizontalLocation][VerticalLocation] &=~ (1<<TailSnake);
  }
  
inline void cSnake::Drawing(){
  World->WorldBlocks[HorizontalLocation][VerticalLocation]|= 1<<HeadSnake;
  }
  
void cSnake::MoveSnake(const int& V,const int& H){
  LCD->createChar(0,World->WorldBlocks[HorizontalLocation]);
  Time=400;
  //World->CheckWorld(VertGlobal, HorizontalLocation, BSnake, VerticalLocation);
  if(World->UpSnake){
    LongSnake++;
    ChangeSnake = true;
    }
  if(H>900&&V>400&&V<600)
    MoveRight(); 
   else if(H<100&&V>400&&V<600)
    MoveLeft();
   else if(V>900&&H>400&&H<600)
    MoveDown();
   else if(V<100&&H>400&&H<600)
    MoveUp();
  }
  
void cSnake::MoveRight(){
  if(HeadSnake==0){
      Time = 50;
      Clear();
      HeadSnake = TailSnake = 4;
      HorizontalLocation++;
      World->DrawingUnits(true, HorizontalLocation, VertGlobal);
      Drawing();
    }
    else if(ChangeSnake){
      HeadSnake--;
      Drawing();
      ChangeSnake = false;
    }
    else{
      Clear();
      LCD->setCursor(HorizontalLocation,VertGlobal);
      HeadSnake--;
      TailSnake--;
      Drawing();
    }
    LCD->write(byte(0));
    delay(Time);
}

void cSnake::MoveLeft(){
  if(HeadSnake == 4){
      Time = 50;
      HorizontalLocation--;
      Clear();   
      HeadSnake = 0;
      World->DrawingUnits(true, HorizontalLocation, VertGlobal);
      Drawing();
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      World->WorldBlocks[HorizontalLocation][VerticalLocation]&= ~(1 << TailSnake);
      HeadSnake++;
      Drawing();
    }
    LCD->write(byte(0));
    delay(Time);
  }
  
void cSnake::MoveDown(){
    Clear();  
    if(VerticalLocation==7){
      VerticalLocation=0;
      VertGlobal++;
      World->DrawingUnits();
      Time=0;
    }
    else
      VerticalLocation++;
    Drawing();
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }
  
void cSnake::MoveUp(){
    Clear();
    if(VerticalLocation==0){
        VerticalLocation=7;
        VertGlobal--;
        World->DrawingUnits();
        Time=0;
      }
    else
        VerticalLocation--;
    Drawing();
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }

void cSnake::Start(){
    LCD->createChar(0,World->WorldBlocks[0]);
    LCD->setCursor(HorizontalLocation,VertGlobal); 
    World->WorldBlocks[0][0]|= 1<<4;
    LCD->write(byte(0));
  }
void cSnake::Again(){
    VerticalLocation = Time = HorizontalLocation = VertGlobal = 0;
    Start();
  }
