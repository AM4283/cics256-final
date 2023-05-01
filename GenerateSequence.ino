const byte buttons[]={34,0,35};
int SIZE = 10;

int sequence[10];
int j = 0; // index of sequence that player is on
int n = 3; // number of Buttons

int curStates[3];
int prevStates[3];

void setup() {
  Serial.begin(9600);
  for(byte i=0;i<3;i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  for (int i=0; i<n; i++) { // Initialize prevStates values to 1 because buttons default to high
    prevStates[i] = 1;
  }
  generateSequence(SIZE, n);
  printArr();
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

void loop() {
  int isPressed = 0; // Default to False
  int buttonPressed = -1;
  for (int i = 0; i<3; i++) {
    curStates[i] = digitalRead(buttons[i]);
  }
  
  for (int i = 0; i<n; i++) {
    if (!curStates[i] && prevStates[i]) { // button pressed
      isPressed = 1;
      buttonPressed = i;
      break;
    }
    prevStates[i] = curStates[i]; // Seems to be not correctly updating prevStates

  } // NEED TO IMPLEMENT BUTTON DEBOUNCING?? OR JUST USE DELAY

  if (isPressed) {
    if (buttonPressed == sequence[j]) {
      Serial.println("Correct!");
      j++;
    }
    else {
      Serial.println("Wrong!");
      Serial.print("Final Score: ");
      Serial.println(j);
      Serial.println("Try Again!");
      generateSequence(SIZE, n);
      printArr();
      j=0;
    }
    delay(500);
  }
}

