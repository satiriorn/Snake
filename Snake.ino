#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "cSnake.h"
#include "cMainMenu.h"

byte symb[8]={B11111,B11111,B11111,B11111,B11111,B11111};
LiquidCrystal_I2C lcd (0x27,16,2);
const LiquidCrystal_I2C *LCD = &lcd;
const int V = 1;
const int H = 0;
cMainMenu *menu;



void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(2000);
  lcd.init();
  lcd.backlight();
  cMainMenu Menu(LCD);
  menu =&Menu;
  
}

void loop() {    
  int vert, horiz;
  vert = analogRead(V);
  horiz = analogRead(H);
  //lcd.begin(16,2);
  lcd.write(byte(0)); 
  lcd.setCursor(0,1);
  delay(5000);
  if(horiz<=100)
        menu->SetActiveMenu(true);
  else if(horiz>=980)
        menu->SetActiveMenu(false);
        
}
