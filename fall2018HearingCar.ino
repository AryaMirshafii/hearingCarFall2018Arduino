
// Frequency for horn: 400 Hz
// Frequency for siren: 900 Hz

#include <AudioFrequencyMeter.h>
#include "SoftwareSerial.h"
#include "AudioFrequencyMeter.h"

//AudioFrequencyMeter meter;
int frequencyPin = A0;
int rightPin = 6;
int leftPin = 7;


float frequency = 0;

int leftSound = 0;
int rightSound = 0;
void calcDirectionAndFreq();
void writeToBLE(int isLeft, float freq);
AudioFrequencyMeter meter;
SoftwareSerial bluetooth(12, 13); //RX, TX



void setup() {


  Serial.begin(9600);
  bluetooth.begin(9600); 
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);

  meter.setBandwidth(60.00, 1500);
  meter.begin(frequencyPin, 45000);
  



}

void loop() {
  meter.begin(frequencyPin, 45000);
  calcDirectionAndFreq();
  //btConnection.flush();
  
  //bluetooth.println("Aryaaa");
  //delay(500);
}



void calcDirectionAndFreq(){
  frequency = meter.getFrequency();
  leftSound = digitalRead(leftPin);
  rightSound = digitalRead(rightPin);

  if(leftSound == HIGH && rightSound == LOW){
  // For debugging only
    Serial.println("The Sound is coming from the left");
    
    //lcd.print("Sound from left");

  }else if (leftSound == LOW && rightSound == HIGH){
  // For debugging only

  
  //lcd.print("Sound from Right");

    Serial.println("The Sound is coming from the right");
  }

  



  
  writeToBLE(leftSound, frequency);
  
  Serial.print("With a frequency of");
  Serial.println(frequency);



}





// take in ints
// 1 = Left siren
// 2 = left horn
// 3 = right siren
// 4 = right horn
void writeToBLE(int isLeft, float freq){
  

  //Serial.println(isLeft);
  //Serial.println(freq);
    if(freq >= 350 && freq <= 450){
       // its a horn

       if(isLeft){
          bluetooth.println(2);
          return;
       }else{
          bluetooth.println(4);
          return;
       }


    }else if( freq >= 850 && freq <= 950){
      // its a siren

      if(isLeft){
          bluetooth.println(1);
          return;
          



       }else if(freq  != -1){
          bluetooth.println(3);

          return;
       }

    }
  meter.end();
  bluetooth.println(5);


}
