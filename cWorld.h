#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "cFood.h"



class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L, const cFood* F);
  void DrawingUnits();
  void CheckWorld(const uint8_t &VertGloval,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation);
  void CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV);
  void MergeFood();
  bool GameOver = false;
  bool UpSnake = false;
  bool Create = true;
  byte WorldBlocks[32][8];
  
  private:
  const LiquidCrystal_I2C* LCD = nullptr;
  cFood* Food = nullptr;

  };
