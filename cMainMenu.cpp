#include "cMainMenu.h"


cMainMenu::cMainMenu(const LiquidCrystal_I2C* L, cWorld* W){
  LCD=L;
  World = W;
  Welcome();
}

inline void cMainMenu::Welcome(){Print("Welcome in Snake", 0, 0); DoMenu();}
  
inline void cMainMenu::DoMenu(){
  LCD->clear();
  LCD->setCursor(0,0);
  LCD->print("Choose an item");
  LCD->setCursor(0,1);
  LCD->print("Arcade or Training");
}
  
void cMainMenu::SetActiveMenu(bool ActiveItemOne){
  if(ActiveItemOne){
    World->Mode = true;
    Print("Training", 5, 0);        
   }
  else
    Print("Arcade", 5, 0);
  LCD->clear();
}
void cMainMenu::GameOver(){Print("Game Over", 4, 0);PrintScore();DoMenu();}
void cMainMenu::Win(){Print("You Win!", 4, 0);PrintScore();DoMenu();}

inline void cMainMenu::PrintScore(){  
  LCD->setCursor(4,1);
  LCD->print("Score:"+String(World->Score));
  delay(3000);
}
inline void cMainMenu::Print(String message = "", uint8_t valueH = 0,uint8_t valueV = 0,uint32_t Time = 1000){
  LCD->clear();
  LCD->setCursor(valueH,valueV);
  LCD->print(message);
  delay(Time);
}
