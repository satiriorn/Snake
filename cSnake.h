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
  int HorizontalLocation; 
  int VertGlobal;
  
  private:
  inline void Clear();
  inline void Drawing();
  int LongSnake;
  int Time;
  int VerticalLocation;
  int HeadSnake;
  int TailSnake;
  bool ChangeSnake = false;
  const LiquidCrystal_I2C* LCD = nullptr;
  cWorld* World = nullptr;

  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
    };
