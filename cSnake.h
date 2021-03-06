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
  void Again();
  void Start();
  void MoveSnake(const int& V,const int& H);
  int8_t HorizontalLocation; 
  int8_t VertGlobal;

  private:
  typedef struct Body{
    uint8_t VertGlobal;
    uint8_t VertLocation;
    uint8_t HorizLocation;
    uint8_t PositionPixel;
  };
  vector<Body> bodyArray;
  
  inline void Clear(const int8_t& VerticalLocation = 0, const int8_t& HorizontalLocation = 0);
  inline void Drawing();
  inline void ClearVisibleArea(const int8_t& h = 0);
  inline void ShiftSpace();
  inline void PreparationArea();
  inline void CheckForLoss(Body part);

  uint8_t LongSnake;
  uint8_t SpeedSnake;
  uint16_t Time;
  uint8_t VerticalLocation;
  uint8_t HeadSnake;
  uint8_t TailSnake;
  int v;
  int h;
  
  bool ChangeSnake = false;
  bool Make = false;
  
  const LiquidCrystal_I2C* LCD = nullptr;
  cWorld* World = nullptr;

  void SetValueBody(const uint8_t &VGlobal,const uint8_t &HLocation, const uint8_t &VLocation, const uint8_t &HeadSnake);
  void CheckGlobalVertical();
  void CheckHead();
  void UpSnake(bool Side = false, uint8_t* value = nullptr);
  void VisibleArea();
  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
  void TravelSystem(const int& V,const int& H);
  void Movements(uint8_t* value = nullptr, bool location = false);
  

  
};
