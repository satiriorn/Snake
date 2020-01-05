#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L,const cFood* F){
  LCD = L;
  Food = F;
 }

void cSnake::MoveSnake(int V, int H){
  LCD->createChar(0,ByteSnake); 
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
      LCD->clear();
      Food->ReturnFood();
      LCD->setCursor(HorizontalLocation,VertGlobal);
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation] = ByteSnake[VerticalLocation]>>1;
    }
    Serial.print(ByteSnake[VerticalLocation]);
    LCD->write(byte(0));
    delay(800);
}
void cSnake::MoveLeft(){
  if(ByteSnake[VerticalLocation]==16){
      HorizontalLocation--;
      ByteSnake[VerticalLocation]=0;   
    }  
    else if(ByteSnake[VerticalLocation]==0){
           ByteSnake[VerticalLocation] = 1;
           LCD->clear(); 
           Food->ReturnFood();
           LCD->setCursor(HorizontalLocation,VertGlobal);
    }
    else{
      LCD->setCursor(HorizontalLocation,VertGlobal);
      ByteSnake[VerticalLocation] = ByteSnake[VerticalLocation]<<1;
    }
    Serial.print(ByteSnake[VerticalLocation]);
    LCD->write(byte(0));
    delay(800);
  }
void cSnake::MoveDown(){
    int Time=800;
    byte a = ByteSnake[VerticalLocation];
    ByteSnake[VerticalLocation] = 0;
    if(VerticalLocation==7){
      VerticalLocation=0;
      VertGlobal++;
      LCD->clear();
      Food->ReturnFood();
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
    int Time = 800;
    ByteSnake[VerticalLocation] = 0;
    if(VerticalLocation==0){
        VerticalLocation=7;
        VertGlobal--;
        LCD->clear();
        Food->ReturnFood();
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
