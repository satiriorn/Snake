#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


class cSnake{
  public:
  cSnake(const LiquidCrystal_I2C* L);
  
  private:
  byte snake[8]={B10000,B00000,B00000,B00000,B00000,B00000,B00000};
  const LiquidCrystal_I2C* LCD = nullptr;
  virtual void MoveSnake();
  
  
    };
