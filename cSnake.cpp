#include "cSnake.h"

cSnake::cSnake(const LiquidCrystal_I2C* L){
  LCD = L;
 }

void cSnake::MoveSnake(int V, int H){
  LCD->createChar(0,ByteSnake); 
  if(H>900&&HorizontalLocation!=16&&V>400&&V<600){
      if(ByteSnake[VerticalLocation]==0){
        HorizontalLocation++;
        ByteSnake[VerticalLocation]=16;
        LCD->clear();
        LCD->setCursor(HorizontalLocation,VertGlobal);
      }
      else{
        LCD->setCursor(HorizontalLocation,VertGlobal);
        ByteSnake[VerticalLocation] = ByteSnake[VerticalLocation]>>1;
      }
      Serial.print(ByteSnake[0]);
      LCD->write(0);
      delay(1000);
   }
   else if(V>900&&H>400&&H<600){
      byte a = ByteSnake[VerticalLocation];
      ByteSnake[VerticalLocation] = 0;
      if(VerticalLocation==7){
        VerticalLocation=0;
        VertGlobal++;
        LCD->clear();
        ByteSnake[VerticalLocation] = a;
        LCD->setCursor(HorizontalLocation,VertGlobal);
      }
      else{
        VerticalLocation++;
      }
      ByteSnake[VerticalLocation] = a;      
      LCD->write(0);
      Serial.print(VerticalLocation);
      delay(1000);
    }
   else if(V<100&&H>400&&H<600){
      byte a = ByteSnake[VerticalLocation];
      ByteSnake[VerticalLocation] = 0;
      if(VerticalLocation==0){
          VerticalLocation=7;
          VertGlobal--;
          LCD->clear();
          ByteSnake[VerticalLocation] = a;
          LCD->setCursor(HorizontalLocation,VertGlobal);
        }
      else{
          VerticalLocation--;
        }
      ByteSnake[VerticalLocation] = a;
      LCD->clear();
      LCD->write(0);
      delay(1000);
    }
  }
