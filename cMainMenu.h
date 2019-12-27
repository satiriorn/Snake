#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class cMainMenu{
  public:
      cMainMenu(const LiquidCrystal_I2C* L);
      virtual void SetActiveMenu(bool active);
  private:
    virtual void Welcome();
    virtual void DoMenu();
    const LiquidCrystal_I2C* LCD = nullptr;
    };
