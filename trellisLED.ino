#include <Wire.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
#define INTPIN 5

void setup() {
  Serial.begin(9600);

  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  
  trellis.begin(0x70);
  trellis.setBrightness(150);
  for (uint8_t i=0; i<16; i++) {
    trellis.clrLED(i);
  }
  trellis.writeDisplay();
}

void toggle(int placeVal) {
 if (trellis.isLED(placeVal))
    trellis.clrLED(placeVal);
  else
    trellis.setLED(placeVal);
}

void loop() {
  delay(500); // 100ms delay is required, dont remove me!
 
  
  // if (trellis.readSwitches()) {
  //   // go through every button
  //   for (uint8_t i=0; i<numKeys; i++) {
  //     // if it was pressed, add it to the list!
  //     if (trellis.justPressed(i)) {
  //       nextFrame[i] = 1;
  //     }
  //   }
  // }  
  for (int i=0; i<16; i++) {
    toggle(i);
  }
  trellis.writeDisplay();
  // Update the map
  // for (uint8_t i=0; i<numKeys; i++) {
  //   if(nextFrame[i] == 1) {
  //     trellis.setLED(i);
  //   } else {
  //     trellis.clrLED(i);
  //   }
  // } 

}