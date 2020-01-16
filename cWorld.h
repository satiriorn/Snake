#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cFood.h"


class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L,const cFood* F);
  void DrawingUnits(bool Horintal=false, const uint8_t &HorizontalLocation = 0, const uint8_t &VertGlobal = 0);
  void CheckWorld(const uint8_t &VertGloval,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation);
  void CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV);
  bool GameOver = false;
  bool UpSnake = false;
  bool Create = true;
  byte WorldBlocks[32][8];
  
  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  const cFood* Food = nullptr;

  };
