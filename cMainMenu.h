#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cSnake.h"

class cMainMenu{
  public:
      cMainMenu(const LiquidCrystal_I2C* L);
      virtual void SetActiveMenu(bool active);
      virtual void GameOver();
      virtual void Win();
  private:
      virtual void Welcome();
      virtual void DoMenu();
    
      const LiquidCrystal_I2C* LCD = nullptr;
    };
