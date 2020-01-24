#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L, cWorld* W){
  LCD = L;
  World = W;
  VerticalLocation = Time = HorizontalLocation = VertGlobal = 0;
  LongSnake =  1;
  HeadSnake = TailSnake = 4;
}
 
inline void cSnake::Clear(){World->WorldBlocks[HorizontalLocation][VerticalLocation] &=~ (1<<TailSnake);}  
inline void cSnake::Drawing(){World->WorldBlocks[HorizontalLocation][VerticalLocation]|= 1<<HeadSnake;}
inline void cSnake::ClearVisibleArea(){World->WorldBlocks[HorizontalLocation-1][VerticalLocation] = B00000;} 

void cSnake::MoveSnake(const int& V,const int& H){
  Time=200;
  Make = false;
  World->CheckWorld(VertGlobal, HorizontalLocation, VerticalLocation, HeadSnake);
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
   VisibleArea();
   delay(Time);
}

void cSnake::VisibleArea(){
  int8_t h = 0;
  for(uint8_t i = 0; i<=2;i++){
    h = (h==2&&HorizontalLocation>0)? h=-1:h; 
    Serial.print(h);
    LCD->createChar(i,World->WorldBlocks[HorizontalLocation+h]);
    LCD->setCursor(HorizontalLocation+h,VertGlobal);
    LCD->write(byte(i));
    h++;
  }
}

void cSnake::CheckHead(){
  LCD->clear();
  Clear();
  World->ReturnFood();
  (HeadSnake==MaxValue) ? HorizontalLocation-- : HorizontalLocation++;
  HeadSnake = (HeadSnake==MaxValue) ? MinValue : MaxValue;
  if(LongSnake > 1 && HeadSnake==MaxValue)
    TailSnake--;
  else if(LongSnake > 1 && HeadSnake==MinValue)
    TailSnake++;
  LCD->setCursor(HorizontalLocation,VertGlobal);
  Drawing();
  Make = true;
}
  
void cSnake::CheckGlobalVertical(){
  (VerticalLocation==MinValue) ? VertGlobal-- : VertGlobal++;
  VerticalLocation =(VerticalLocation == 7) ? MinValue : 7; 
  LCD->clear();
  World->ReturnFood();
}
  
void cSnake::CheckTail(){
  LCD->clear();
  World->ReturnFood();
  Clear();
  TailSnake = (TailSnake==MaxValue) ? MinValue : MaxValue;
  if(LongSnake > 1 && TailSnake==MaxValue){
    HeadSnake--;
    Drawing();
    }
  else if(LongSnake > 1 && TailSnake==MinValue){
    HeadSnake++;
    Drawing();
  }
  Make = true;
}
  
void cSnake::MoveRight(){
  if(ChangeSnake)
    UpSnake(true);
  if(TailSnake==0){
    CheckTail();
    ClearVisibleArea();
    }
  if(HeadSnake==0)
    CheckHead();
  else if(Make==false){
    Clear();
    TailSnake--;
    HeadSnake--;
    Drawing();
  }
}

void cSnake::MoveLeft(){
  if(ChangeSnake)
    UpSnake();
  if(TailSnake==4){
    CheckTail(); 
    ClearVisibleArea();
  }
  if(HeadSnake == 4)
    CheckHead();
  else if(Make==false){ 
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
  
void cSnake::UpSnake(bool Horizontal = false){
    (Horizontal)?HeadSnake--:HeadSnake++;
    Drawing();
    ChangeSnake = false;
}
  
void cSnake::Start(){
    World->WorldBlocks[0][0]|= 1<<MaxValue;
    LCD->createChar(0,World->WorldBlocks[0]);
    LCD->setCursor(HorizontalLocation,VertGlobal); 
    LCD->write(byte(0)); 
}
  
void cSnake::Again(){
    VerticalLocation = Time = HorizontalLocation = VertGlobal = 0;
    Start();
}
