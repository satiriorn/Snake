#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L, cWorld* W){
  LCD = L;
  World = W;
  VerticalLocation = Time = HorizontalLocation = VertGlobal = h = v = MinValue;
  LongSnake =  1;
  HeadSnake = TailSnake = MaxValue;
}
  
inline void cSnake::Clear(const int8_t& VerticalLocation = 0, const int8_t& HorizontalLocation = 0){World->WorldBlocks[HorizontalLocation][VerticalLocation] &=~ (1<<TailSnake);}  
inline void cSnake::Drawing(){World->WorldBlocks[HorizontalLocation][VerticalLocation]|= 1<<HeadSnake;}
inline void cSnake::ClearVisibleArea(const int8_t& h = 0){World->WorldBlocks[HorizontalLocation+h][VerticalLocation] = B00000;} 
inline void cSnake::ShiftSpace(){
  for(uint16_t i = MinValue ; i<(LongSnake-1);i++){
    Body x = bodyArray[i+1];
    bodyArray[i] = x;
  }
}
inline void cSnake::PreparationArea(){LCD->clear();World->ReturnFood();}

void cSnake::MoveSnake(const int& V,const int& H){
  Time = 200;
  Make = false;
  World->CheckWorld(VertGlobal, HorizontalLocation, VerticalLocation, HeadSnake);
  if(World->UpSnake){
    LongSnake++;
    ChangeSnake = true;
    }
  TravelSystem(V,H);
   VisibleArea();
   delay(Time);
}
  
void cSnake::MoveRight(){
  if(ChangeSnake)
    UpSnake(true,&HeadSnake);
  if(HeadSnake==MinValue)
    CheckHead();
  else if(Make==false)
    Movements(&HeadSnake);
}

void cSnake::MoveLeft(){
  if(ChangeSnake)
    UpSnake(false,&HeadSnake);
  if(HeadSnake == MaxValue)
    CheckHead();
  else if(Make==false)
    Movements(&HeadSnake, true);
}
 
void cSnake::MoveDown(){
  if(ChangeSnake)
    UpSnake(false,&VerticalLocation);
  else if(VerticalLocation==7)
    CheckGlobalVertical();
  else
    Movements(&VerticalLocation,true);
}
  
void cSnake::MoveUp(){
  if(ChangeSnake)
    UpSnake(true,&VerticalLocation);
  if(VerticalLocation==MinValue)
    CheckGlobalVertical();
  else
    Movements(&VerticalLocation);
}
  
void cSnake::UpSnake(bool Side = false,uint8_t* value = 0){
  SetValueBody(VertGlobal, HorizontalLocation, VerticalLocation, HeadSnake);
  *value = (Side)?*value-=1:*value+=1;
  Drawing();
  ChangeSnake = false;
}

void cSnake::Movements(uint8_t* value = nullptr, bool location = false){
  SetValueBody(VertGlobal, HorizontalLocation, VerticalLocation, HeadSnake);
  if((TailSnake==MaxValue&&location==true)||(TailSnake==MinValue&&location==false))
    (location==false)?ClearVisibleArea(-1):ClearVisibleArea(1);
  *value = (location==false) ? *value-=1:*value+=1;
  Drawing();
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
  SetValueBody(VertGlobal, HorizontalLocation, VerticalLocation, HeadSnake);
  (HeadSnake==MaxValue) ? HorizontalLocation-- : HorizontalLocation++;
  HeadSnake = (HeadSnake==MaxValue) ? MinValue : MaxValue;
  LCD->setCursor(HorizontalLocation,VertGlobal);
  Drawing();
  Make = true;
}
  
void cSnake::CheckGlobalVertical(){
  (VerticalLocation==MinValue) ? VertGlobal-- : VertGlobal++;
  VerticalLocation =(VerticalLocation == 7) ? 0 : 7; 
  LCD->clear();
  World->ReturnFood();
}

void cSnake::Start(){
  World->WorldBlocks[0][0]|= 1<<MaxValue;
  LCD->createChar(0,World->WorldBlocks[0]);
  LCD->setCursor(HorizontalLocation,VertGlobal); 
  LCD->write(byte(0)); 
  h = 1000;
  v = 500;
}

void cSnake::Again(){VerticalLocation = Time = HorizontalLocation = VertGlobal = 0; Start();}

void cSnake::SetValueBody(const uint8_t &VGlobal,const uint8_t &HLocation, const uint8_t &VLocation, const uint8_t &HeadSnake){
  Body part = {VGlobal, VLocation, HLocation, HeadSnake};
  if(bodyArray.size()!=(LongSnake-1))
    bodyArray.push_back(part);
  ShiftSpace();
  bodyArray[LongSnake-1] = part;
  TailSnake = bodyArray[0].PositionPixel;
  Clear(bodyArray[0].VertLocation, bodyArray[0].HorizLocation);
}

void cSnake::TravelSystem(const int& V,const int& H){
   if(H>900&&V>400&&V<600)
    MoveRight(); 
   else if(H<100&&V>400&&V<600)
    MoveLeft();
   else if(V>900&&H>400&&H<600)
    MoveDown();
   else if(V<100&&H>400&&H<600)
    MoveUp();
   else if(World->Mode==false)
    TravelSystem(v,h);
   if((H>900&&V>400&&V<600)||(H<100&&V>400&&V<600)||(V>900&&H>400&&H<600)||(V<100&&H>400&&H<600)){
      h = H;
      v = V;
    }
}
