#include "SoftwareSerial.h"
SoftwareSerial bluetooth(12, 13); //RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HI");
  bluetooth.println("1");

}
