#pragma once
#include <Arduino.h>
#include "cWorld.h"
#include <LiquidCrystal_I2C.h>


class cSnake{
  public:
  cSnake(const LiquidCrystal_I2C* L, cWorld* W);
  virtual void Start();
  virtual void Again();
  virtual void MoveSnake(const int& V,const int& H);
  uint8_t HorizontalLocation; 
  uint8_t VertGlobal;

  
  private:
  inline void Clear();
  inline void Drawing();
  uint8_t LongSnake;
  uint16_t Time;
  uint8_t VerticalLocation;
  uint8_t HeadSnake;
  uint8_t TailSnake;
  
  const uint8_t MaxValue = 4;
  const uint8_t MinValue = 0;
  
  bool ChangeSnake = false;
  
  const LiquidCrystal_I2C* LCD = nullptr;
  cWorld* World = nullptr;
  
  void CheckGlobalVertical();
  void CheckHead();
  void CheckTail();
  
  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
    };
