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
  int8_t HorizontalLocation; 
  int8_t VertGlobal;

  private:
  inline void Clear();
  inline void Drawing();
  inline void ClearVisibleArea(int8_t h = 0);

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
  void UpSnake(bool Horizontal = false);
  void VisibleArea();
  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
    };
