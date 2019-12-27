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
  LCD->clear();
  }
void cMainMenu::SetActiveMenu(bool ActiveItemOne){
    if(ActiveItemOne){
        LCD->clear();
        LCD->setCursor(5,0);
        LCD->print("Training");
      }
    else{
        LCD->clear();
        LCD->setCursor(5,0);
        LCD->print("Arcade");
      }
  }
