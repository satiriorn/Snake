#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cWorld.h"

class cMainMenu{
  public:
      explicit cMainMenu(const LiquidCrystal_I2C* L,cWorld *W);
      void SetActiveMenu(bool active);
      void GameOver();
      void Win();
  private:
      inline void Welcome();
      void DoMenu();
      void Print(String message, uint8_t valueH,uint8_t valueV,uint32_t Time = 1000);
      cWorld *World = nullptr;
      const LiquidCrystal_I2C* LCD = nullptr;
};
