#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class cWorld{
  public:
  explicit cWorld(const LiquidCrystal_I2C* L);
  void CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, const uint8_t &VerticalLocation, const uint8_t &HeadSnake);
  void CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV);
  void ReturnFood();
  void GetValueFood(const uint8_t& FoodLocationV, const uint8_t& FoodLocationH,const uint8_t& RandomFoodLocation,const uint8_t& VerticalLocalFood);
  void MergeFood();
  bool GameOver;
  bool UpSnake;
  bool Create = true;
  bool SpawnFood;
  bool Mode = false;
  uint32_t Score = 1;
  byte WorldBlocks[32][8];
  
  private:
  uint8_t* FLV = nullptr;
  uint8_t* FLH = nullptr;
  uint8_t* RLV = nullptr;
  uint8_t* VLF = nullptr;
  const LiquidCrystal_I2C* LCD = nullptr;
  };
