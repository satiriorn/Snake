#pragma once
#include <Arduino.h>
#include "cWorld.h"
#include <LiquidCrystal_I2C.h>

#define MaxValue 4
#define MinValue 0

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
  void UpSnake(bool Horizontal = false);
  void VisibleArea();
  void ClearVisibleArea();
  uint8_t LongSnake;
  uint8_t SpeedSnake;
  uint16_t Time;
  uint8_t VerticalLocation;
  uint8_t HeadSnake;
  uint8_t TailSnake;
  
  bool ChangeSnake = false;
  bool Make = false;
  
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
