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
    uint8_t FoodLocationV;
    uint8_t FoodLocationH;
    uint8_t VerticalLocalFood;
    uint8_t RandomFoodLocation;
    byte Foods[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
    
  private:
    const LiquidCrystal_I2C* LCD = nullptr;
  };
