#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L, const cWorld* W){
  LCD = L;
  World = W;
 }

void cSnake::MoveSnake(int V, int H){
  LCD->createChar(0,ByteSnake); 
  World->CheckWorld(VertGlobal, HorizontalLocation, BSnake, VerticalLocation);
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
  if(ByteSnake[VerticalLocation]==0){
      HorizontalLocation++;
      ByteSnake[VerticalLocation]=16;
      World->DrawingUnits(true, HorizontalLocation, VertGlobal);
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation] = ByteSnake[VerticalLocation]>>1;
    }
    LCD->write(byte(0));
    //World->DrawingUnits(true, HorizontalLocation, VertGlobal);
    delay(400);
}
void cSnake::MoveLeft(){
  if(ByteSnake[VerticalLocation]==16){
      HorizontalLocation--;
      ByteSnake[VerticalLocation]=0;   
    }  
    else if(ByteSnake[VerticalLocation]==0){
       ByteSnake[VerticalLocation] = 1;
       World->DrawingUnits(true, HorizontalLocation, VertGlobal);
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation] = ByteSnake[VerticalLocation]<<1;
    }
    LCD->write(byte(0));
    delay(400);
  }
void cSnake::MoveDown(){
    int Time=400;
    byte a = ByteSnake[VerticalLocation];
    ByteSnake[VerticalLocation] = 0;
    if(VerticalLocation==7){
      VerticalLocation=0;
      VertGlobal++;
      World->DrawingUnits();
      Time=0;
    }
    else
      VerticalLocation++;
    ByteSnake[VerticalLocation] = a;  
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }
  
void cSnake::MoveUp(){
    byte a = ByteSnake[VerticalLocation];
    int Time = 400;
    ByteSnake[VerticalLocation] = 0;
    if(VerticalLocation==0){
        VerticalLocation=7;
        VertGlobal--;
        World->DrawingUnits();
        Time=0;
      }
    else
        VerticalLocation--;
    ByteSnake[VerticalLocation] = a;
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }
  
void cSnake::Start(){
    LCD->createChar(0,ByteSnake);
    LCD->setCursor(HorizontalLocation,VertGlobal); 
    LCD->write(byte(0));
  }
