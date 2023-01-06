//Room Access Management Challenge
//Author: Giovane Carvalho Silvério
//06/01/2023

//-- Includes --
#include "MenuSerial.h"
#include "User.h"

//-- Declarations --
MenuSerial menu;
User user;

//-- Setup --
void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

//-- Main Loop --
void loop() {
  
}
