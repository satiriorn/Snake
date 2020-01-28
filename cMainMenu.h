#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cWorld.h"

class cMainMenu{
  public:
      explicit cMainMenu(const LiquidCrystal_I2C* L);
      virtual void SetActiveMenu(bool active);
      virtual void GameOver();
      virtual void Win();
  private:
      virtual void Welcome();
      virtual void DoMenu();
      cWorld *World = nullptr;
      const LiquidCrystal_I2C* LCD = nullptr;
    };
