#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class cWorld{
  public:
  cWorld(const LiquidCrystal_I2C* L);
  void CheckWorld(const uint8_t &VertGloval,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation);
  void CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV);
  void ReturnFood();
  void GetValueFood(const uint8_t& FoodLocationV, const uint8_t& FoodLocationH,const uint8_t& RandomFoodLocation,const uint8_t& VerticalLocalFood);
  void MergeFood();
  bool GameOver = false;
  bool UpSnake = false;
  bool Create = true;
  byte WorldBlocks[32][8];
  
  private:
  uint8_t* FLV = nullptr;
  uint8_t* FLH = nullptr;
  uint8_t* RLV = nullptr;
  uint8_t* VLF = nullptr;
  const LiquidCrystal_I2C* LCD = nullptr;
  
  };
