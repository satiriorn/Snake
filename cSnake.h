#pragma once
#include <Arduino.h>
#include "cWorld.h"
#include <LiquidCrystal_I2C.h>
#include <vector.h>


#define MaxValue 4
#define MinValue 0

class cSnake{
  public:
  explicit cSnake(const LiquidCrystal_I2C* L, cWorld* W);
  virtual void Start();
  virtual void Again();
  virtual void MoveSnake(const int& V,const int& H);
  int8_t HorizontalLocation; 
  int8_t VertGlobal;

  private:
  inline void Clear(const int8_t& VerticalLocation = 0, const int8_t& HorizontalLocation = 0);
  inline void Drawing();
  inline void ClearVisibleArea(const int8_t& h = 0);

  uint8_t LongSnake;
  uint8_t SpeedSnake;
  uint16_t Time;
  uint8_t VerticalLocation;
  uint8_t HeadSnake;
  uint8_t TailSnake;
  
  bool ChangeSnake = false;
  bool Make = false;
  
  const LiquidCrystal_I2C* LCD = nullptr;
  cWorld* World = nullptr;
  
  void CheckGlobalVertical();
  void CheckHead();
  void UpSnake(bool Side = false, uint8_t* value = nullptr);
  void VisibleArea();
  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
  void PreparationArea();
  void Movements(uint8_t* value = nullptr, bool location = false);
  void ShiftSpace();
  
  struct Body{
  uint8_t VertGlobal;
  uint8_t VertLocation;
  uint8_t HorizLocation;
  uint8_t PositionPixel;
  };
  
  void SetValueBody(const uint8_t &VGlobal,const uint8_t &HLocation, const uint8_t &VLocation, const uint8_t &HeadSnake);
  vector<Body> bodyArray;
};
