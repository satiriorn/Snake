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
      inline void PrintScore();
      inline void Print(String message = "", uint8_t valueH = 0,uint8_t valueV = 0,uint32_t Time = 1000);
      inline void DoMenu();
      cWorld *World = nullptr;
      const LiquidCrystal_I2C* LCD = nullptr;
};
