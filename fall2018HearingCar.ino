
// Frequency for horn: 400 Hz
// Frequency for siren: 900 Hz

#include <AudioFrequencyMeter.h>
#include "SoftwareSerial.h"
#include "AudioFrequencyMeter.h"



//AudioFrequencyMeter meter;
int inputPin = A0;
int rightPin = 6;
int leftPin = 7;


float frequency = 0;
int frequencyPin;
int leftSound = 0;
int rightSound = 0;

AudioFrequencyMeter meter;
SoftwareSerial mySerial(12, 13); //RX, TX

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);

  meter.setBandwidth(70.00, 1500);    // Ignore frequency out of this range
  meter.begin(frequencyPin, 45000);

}

void loop() {
  calcDirectionAndFreq();
}



void calcDirectionAndFreq(){
  frequency = meter.getFrequency();
  leftSound = digitalRead(leftPin);
  rightSound = digitalRead(rightPin);
  
  if(leftSound == HIGH && rightSound == LOW){
    
    Serial.println("The Sound is coming from the left");
  }else if (leftSound == LOW && rightSound == HIGH){
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
    
    if(freq > 350 && freq < 450){
       // its a horn
       
       if(isLeft){
          mySerial.println(2);
       }else{
          mySerial.println(4);
       }
       
       
    }else if(freq > 850 && freq < 950){
      // siren

      if(isLeft){
          mySerial.println(1);
       }else{
          mySerial.println(3);
       }
      
    }

    
    
}










