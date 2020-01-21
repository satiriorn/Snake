#pragma once
#include <Arduino.h>
#include "cWorld.h"
#include <LiquidCrystal_I2C.h>



class cFood{
  public:
    cFood(const LiquidCrystal_I2C* L,const cWorld* W);
    void GenerateFood();
    void Drawing();
    bool SpawnFood = true;

  private:
    const LiquidCrystal_I2C* LCD = nullptr;
    cWorld* World = nullptr;
    uint8_t FoodLocationV;
    uint8_t FoodLocationH;
    uint8_t VerticalLocalFood;
    uint8_t RandomFoodLocation;
  };
