#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


class cSnake{
  public:
  cSnake(const LiquidCrystal_I2C* L);
  virtual void MoveSnake(int V = 0 , int H = 0);
  byte ByteSnake[8] = {
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};


  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  int Vertical = 0;
  int Horizontal = 0;
  int HorizontalLocation = 0;
  int VerticalLocation = 0;
 
    };
