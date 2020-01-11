#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L, const cWorld* W){
  LCD = L;
  World = W;
 }

void cSnake::MoveSnake(int V, int H){
  LCD->createChar(0,ByteSnake); 
  World->CheckWorld(VertGlobal, HorizontalLocation, BSnake, VerticalLocation);
  Time=400;
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
  if(HorizLocal==0){
      Time = 50;
      ByteSnake[VerticalLocation]&=~(1 << HorizLocal);
      HorizLocal = 4;
      HorizontalLocation++;
      World->DrawingUnits(true, HorizontalLocation, VertGlobal);
      ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation]&= ~(1 << HorizLocal);
      HorizLocal--;
      ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    }
    LCD->write(byte(0));
    delay(Time);
}
void cSnake::MoveLeft(){
  if(HorizLocal == 4){
      Time = 50;
      HorizontalLocation--;
      ByteSnake[VerticalLocation]&= ~(1 << HorizLocal);   
      HorizLocal = 0;
      World->DrawingUnits(true, HorizontalLocation, VertGlobal);
      ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation]&= ~(1 << HorizLocal);
      HorizLocal++;
      ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    }
    LCD->write(byte(0));
    delay(Time);
  }
void cSnake::MoveDown(){
    ByteSnake[VerticalLocation]&= ~(1 << HorizLocal);   
    if(VerticalLocation==7){
      VerticalLocation=0;
      VertGlobal++;
      World->DrawingUnits();
      Time=0;
    }
    else
      VerticalLocation++;
    ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }
  
void cSnake::MoveUp(){
    ByteSnake[VerticalLocation]&= ~(1 << HorizLocal);   
    if(VerticalLocation==0){
        VerticalLocation=7;
        VertGlobal--;
        World->DrawingUnits();
        Time=0;
      }
    else
        VerticalLocation--;
    ByteSnake[VerticalLocation]|= 1<<HorizLocal;
    LCD->setCursor(HorizontalLocation,VertGlobal);
    LCD->write(byte(0));
    delay(Time);
  }
void cSnake::Start(){
    LCD->createChar(0,ByteSnake);
    LCD->setCursor(HorizontalLocation,VertGlobal); 
    LCD->write(byte(0));
  }
