#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cFood.h"


class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L,const cFood* F);
  void DrawingUnits(bool Horintal=false, const int &HorizontalLocation = 0, const int &VertGlobal = 0);
  void CheckWorld(const int &VertGloval,const int &HorizontalLocation, byte* ByteSnake, const int &VerticalLocation);
  void CreateWorld(const int &ScaleH, const int &ScaleV);
  bool GameOver = false;
  bool UpSnake = false;
  bool Create = true;
  byte WorldBlocks[32][8];
  
  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  const cFood* Food = nullptr;

  };
