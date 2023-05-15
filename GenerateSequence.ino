#include <Wire.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
#define INTPIN 5

const byte buttons[]={34,0,35};
int SIZE = 10;

int sequence[10];
int j = 0; // index of sequence that player is on (SCORE)
int count = 0; // index of sequence that player is currently on
int n = 16; // number of Buttons

int curStates[3];
int prevStates[3];

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

  generateSequence(SIZE, n);
}

void printArr() {
  for (int i = 0; i<SIZE; i++) {
    Serial.print(sequence[i]);
    Serial.print(", ");
  }
  Serial.println("");
}

void generateSequence(int len, int n) { //Generate a sequence of len numbers [0,n)
  for (int i = 0; i<len; i++) {
    sequence[i] = random(n);
  }
}

void toggle(int placeVal) {
 if (trellis.isLED(placeVal))
    trellis.clrLED(placeVal);
  else
    trellis.setLED(placeVal);
}

int sequenceDone = 0;
void loop() {
  delay(800);
  if(Serial.available()) {
    int paused;
    paused = Serial.read();
    // Serial.println(paused);
    while(paused == 1) {
      delay(1);
    }
  }
  if (sequenceDone == 0) {
    for (int i = 0; i<j+1; i++) {
      toggle(sequence[i]);
      trellis.writeDisplay();
      delay(500);
      toggle(sequence[i]);
      trellis.writeDisplay();
      delay(500);
    }
    sequenceDone = 1;
  }
  int isPressed = 0; // Default to False
  int buttonPressed = -1;
  if (trellis.readSwitches()) {
    for(int i=0; i<16; i++) {
      if (trellis.justPressed(i)) {
        buttonPressed = i;
        isPressed = 1;
        break;
      }
    }
  }
  // byte data[3];
  if (isPressed) { 
    if (buttonPressed == sequence[count]) {
      if (count == j) {
        j++;
        count = 0;
        sequenceDone = 0;
        Serial.write(j);
      }
      else {
        count++;
      }
    }
    else {
      // Serial.println("Wrong!");
      // Serial.print("Final Score: ");
      // Serial.println(j);
      // Serial.println("Try Again!");
      generateSequence(SIZE, n);
      // printArr();
      // data[0] = (byte) j;
      // data[1] = (byte) count;
      // data[2] = (byte) 1;
      // Serial.write(data, 3);
      j=0;
      count = 0;
      sequenceDone = 0;
      Serial.write(j);
    }
  }
}

