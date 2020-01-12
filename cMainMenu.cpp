#include "cMainMenu.h"


cMainMenu::cMainMenu(const LiquidCrystal_I2C* L){
    LCD=L;
    Welcome();
  }
void cMainMenu::Welcome(){
  LCD->setCursor(0,0);
  LCD->print("Welcome in Snake");
  delay(1000);
  DoMenu();
  }
  
void cMainMenu::DoMenu(){
  LCD->clear();
  LCD->setCursor(0,0);
  LCD->print("Choose an item");
  LCD->setCursor(0,1);
  LCD->print("Arcade or Training");
  }
void cMainMenu::SetActiveMenu(bool ActiveItemOne){
  if(ActiveItemOne){
      LCD->clear();
      LCD->setCursor(5,0);
      LCD->print("Training");
      delay(1000);
      LCD->clear();          
    }
  else{
      LCD->clear();
      LCD->setCursor(5,0);
      LCD->print("Arcade");
      delay(1000);
      LCD->clear();
    }
  }

void cMainMenu::GameOver(){
    LCD->clear();
    LCD->setCursor(5,0);
    LCD->print("Game Over");
    delay(3000);
    LCD->clear();
    DoMenu();     
  }

void cMainMenu::Win(){
    LCD->clear();
    LCD->setCursor(5,0);
    LCD->print("You Win!");
    delay(3000);
    DoMenu();
  }
