#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "stdlib.h"

class cFood{
  public:
    cFood(const LiquidCrystal_I2C* L);
    void GenerateFood();
    void ReturnFood();
    bool SpawnFood = true;
    int CursorLocationV = 0;
    int CursorLocationH = 0;
    int arrLocation = 0;
    int RandomPixelLocation = 0;
    byte Foods[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
     };
  private:
    int RandomNumber(const int& value);
    const LiquidCrystal_I2C* LCD = nullptr;
    int mass[5]={16,4,8,2,1};
  };
