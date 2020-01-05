#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


class cSnake{
  public:
  cSnake(const LiquidCrystal_I2C* L);
  virtual void Start();
  virtual void MoveSnake(int V = 0 , int H = 0);

  private:
    byte ByteSnake[8] = {
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
  const LiquidCrystal_I2C* LCD = nullptr;
  int HorizontalLocation = 0;
  int VerticalLocation = 0;
  int VertGlobal = 0;
  void MoveRight();
  void MoveLeft();
  void MoveDown();
  void MoveUp();
    };
