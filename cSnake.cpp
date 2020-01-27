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
inline void cSnake::ClearVisibleArea(const int8_t& h = 0){World->WorldBlocks[HorizontalLocation+h][VerticalLocation] = B00000;} 

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
  
void cSnake::CheckTail(){
  PreparationArea();
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
    UpSnake(true,&HeadSnake);
  if(TailSnake==0){
    CheckTail();
    ClearVisibleArea(-1);
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
    UpSnake(false,&HeadSnake);
  if(TailSnake==4){
    CheckTail(); 
    ClearVisibleArea(1);
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
  if(ChangeSnake)
    UpSnake(false,&VerticalLocation);
  else if(VerticalLocation==7)
    CheckGlobalVertical();
  else{
    Clear();  
    VerticalLocation++;
    Drawing();
  }
}
  
void cSnake::MoveUp(){
  if(ChangeSnake)
    UpSnake(true,&VerticalLocation);
  if(VerticalLocation==0)
    CheckGlobalVertical();
  else{
    Clear();
    VerticalLocation--;
    Drawing();
  }
}
  
void cSnake::UpSnake(bool Side = false,uint8_t* value = 0){
    *value = (Side)?*value-=1:*value+=1;
    Drawing();
    ChangeSnake = false;
}

void cSnake::VisibleArea(){
  int8_t h = 0;
  for(uint8_t i = 0; i<=2;i++){
    h = (h==2&&HorizontalLocation>0)? h=-1:h; 
    LCD->createChar(i,World->WorldBlocks[HorizontalLocation+h]);
    LCD->setCursor(HorizontalLocation+h,VertGlobal);
    LCD->write(byte(i));
    h++;
  }
}

void cSnake::CheckHead(){
  PreparationArea();
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

void cSnake::PreparationArea(){
    LCD->clear();
    World->ReturnFood();
    Clear();
}

void cSnake::SetValue(const uint8_t &VGlobal,const uint8_t &HLocation, const uint8_t &VLocation, const uint8_t &HeadSnake, const uint8_t& LifePeriod){
  Body part = {VGlobal, VLocation, HLocation, HeadSnake, LifePeriod};
  bodyArray[0] = part;
}
