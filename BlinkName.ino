int led1 = LED_BUILTIN;
int buttonPin = 2; // Push button for resetting the name
bool isButtonPressed = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), interruptHandler, FALLING);
}

void loop() {
  // Check if the button was pressed in the interrupt handler
  if (isButtonPressed) {
    resetName();
    isButtonPressed = false;
  }

  
  // V (...-)
  blinkDot(); delay(500);
  blinkDot(); delay(500);
  blinkDot(); delay(500);
  blinkDash(); delay(1000);

  // i (..)
  blinkDot(); delay(500);
  blinkDot(); delay(1000);

  // p (.--.)
  blinkDot(); delay(500);
  blinkDash(); delay(500);
  blinkDot(); delay(500);
  blinkDot(); delay(1000);
  
  // i (..)
  blinkDot(); delay(500);
  blinkDot(); delay(1000);
  
  // n (-.)
  blinkDash(); delay(500);
  blinkDot(); delay(1000);

  delay(2000);  // Gap between words
}
}

void resetName() {
  // Reset the name display here
  digitalWrite(led1, LOW);
  delay(1000);
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
}

void interruptHandler() {
  // Set the flag to indicate the button was pressed
  isButtonPressed = true;
}
