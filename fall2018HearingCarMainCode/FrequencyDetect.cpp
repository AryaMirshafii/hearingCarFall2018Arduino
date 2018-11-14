/*
 * FrequencyDetect.cpp
 *
 *  Created on: Nov 2, 2018
 *      Author: aryamirshafii
 */

#include "FrequencyDetect.h"
#include "Arduino.h"
int samplePin;
int frequency = -1;

FrequencyDetect::FrequencyDetect(int pinNumber) {
	samplePin = pinNumber;

}


void FrequencyDetect::begin(){

}

