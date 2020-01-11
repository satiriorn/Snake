#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cFood.h"

class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L,const cFood* F);
  void DrawingUnits(bool Horintal=false, const int &HorizontalLocation = 0, const int &VertGlobal = 0);
  void CheckWorld(const int &VertGloval,const int &HorizontalLocation, byte* ByteSnake, const int &VerticalLocation);
  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  const cFood* Food = nullptr;
  };
