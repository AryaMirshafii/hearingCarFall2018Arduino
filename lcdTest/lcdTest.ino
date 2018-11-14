
#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 8, 9, 10, 11); //Initialize LCD
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0); 
  lcd.print("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
