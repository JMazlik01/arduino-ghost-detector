
int const potPin = A0;
int potVal = 0;
int ghostC = 0;
int blinkDelay = 250;
int blink = LOW;
bool turnedOn = false;


void setup() {

  // GREEN LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // ORANGE LEDs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // RED LED
  pinMode(7, OUTPUT);
}

void loop() {

  potVal = analogRead(potPin);
  ghostC = map(potVal, 0, 1023, 0, 7);
  turnedOn = ghostC != 0;

  if (turnedOn && blink == LOW) {
    tone(8, 440);
    blink = HIGH;
  } else {
    blink = LOW;
    noTone(8);
  }

  switch (ghostC) {

    case 0:
    
      // TURNED OFF
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      break;

    case 1:
      
      // FIRST GREEN LED
      digitalWrite(2, blink);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      blinkDelay = 500;
      break;
    case 2:

      // SECOND GREEN LED
      digitalWrite(2, HIGH);
      digitalWrite(3, blink);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      blinkDelay = 400;
      break;
    case 3:

      // THIRD GREEN LED
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, blink);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      blinkDelay = 300;
      break;
    case 4:

      // FIRST ORANGE LED
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, blink);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      blinkDelay = 250;
      break;
    case 5:

      // SECOND ORANGE LED
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, blink);
      digitalWrite(7, LOW);

      blinkDelay = 150;
      break;
    default:

      // RED LED
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, blink);

      blinkDelay = 50;
      break;
  }

  delay(blinkDelay);
}
