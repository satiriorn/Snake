#pragma once
#include <Arduino.h>
#include "cWorld.h"
#include <LiquidCrystal_I2C.h>


class cSnake{
  public:
  cSnake(const LiquidCrystal_I2C* L, const cWorld* W);
  virtual void Start();
  virtual void Again();
  virtual void MoveSnake(int V = 0 , int H = 0);
  int HorizontalLocation; 
  int VertGlobal;
  
  
  private:
    byte ByteSnake[8] = {
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
  int LongSnake;
  int Time;
  int VerticalLocation;
  int HorizLocal;
  
  byte* BSnake = ByteSnake;
  const LiquidCrystal_I2C* LCD = nullptr;
  const cWorld* World = nullptr;

  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
    };
