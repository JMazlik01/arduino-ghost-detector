
int const POT_PIN = A0;
int const LED_COUNT = 6;

int potVal = 0;
int pinsOn = 0;
int blinkDelay = 250;
int blink = LOW;
bool turnedOn = false;

int const ledPins[LED_COUNT] = { 2, 3, 4, 5, 6, 7 };
int const blinkDelays[LED_COUNT + 1] = { 500, 500, 400, 300, 250, 150, 50 };

void setup() {

  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {

  potVal = analogRead(POT_PIN);

  // 0 - LED_COUNT + 1 -> +1 for the 'turned off' state
  pinsOn = map(potVal, 0, 1023, 0, LED_COUNT);
  turnedOn = pinsOn != 0;
  blinkDelay = blinkDelays[pinsOn];

  if (turnedOn && blink == LOW) {
    tone(8, 440);
    blink = HIGH;
  } else {
    blink = LOW;
    noTone(8);
  }


  for (int i = 0; i < LED_COUNT; i++) {
      int pin = ledPins[i];

      if (i < pinsOn - 1) {
        digitalWrite(pin, HIGH);
      } 
      else if (i == pinsOn - 1) {
        digitalWrite(pin, blink);
      }
      else {
        digitalWrite(pin, LOW);
      }
    }

  delay(blinkDelay);
}
