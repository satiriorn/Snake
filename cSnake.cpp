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
   LCD->createChar(0,World->WorldBlocks[HorizontalLocation]);
   LCD->setCursor(HorizontalLocation,VertGlobal);
   LCD->write(byte(0));
   delay(Time);
  }
  
void cSnake::CheckHead(){
   Clear();
   (HeadSnake==MaxValue) ? HorizontalLocation-- : HorizontalLocation++;
   HeadSnake = (HeadSnake==MaxValue) ? MinValue : MaxValue;
   LCD->setCursor(HorizontalLocation,VertGlobal);
   Drawing();
  }
  
void cSnake::CheckGlobalVertical(){
      (VerticalLocation==MinValue) ? VertGlobal-- : VertGlobal++;
      VerticalLocation =(VerticalLocation == 7) ? MinValue : 7; 
      LCD->clear();
  }
void cSnake::CheckTail(){
    Clear();
    LCD->clear();
    TailSnake = (TailSnake==MaxValue) ? MinValue : MaxValue;
  }
  
void cSnake::MoveRight(){
  if(TailSnake==0)
    CheckTail();
  if(HeadSnake==0)
    CheckHead();
  else{
    Clear();
    TailSnake--;
    HeadSnake--;
    Drawing();
  }
}

void cSnake::MoveLeft(){
  if(TailSnake==4)
    CheckTail(); 
  if(HeadSnake == 4)
    CheckHead();
  else{ 
    Clear();
    TailSnake++;
    HeadSnake++;
    Drawing();
  }
}
 
void cSnake::MoveDown(){
    Clear();  
    if(VerticalLocation==7)
      CheckGlobalVertical();
    else
      VerticalLocation++;
    Drawing();
    LCD->setCursor(HorizontalLocation,VertGlobal);
  }
  
void cSnake::MoveUp(){
    Clear();
    if(VerticalLocation==0)
      CheckGlobalVertical();
    else
      VerticalLocation--;
    Drawing();
    LCD->setCursor(HorizontalLocation,VertGlobal);
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
