#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cFood.h"

class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L,const cFood* F);
  void DrawingUnits(bool Horintal=false, int HorizontalLocation=0, int VertGlobal=0);
  
  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  const cFood* Food = nullptr;
  
  };
