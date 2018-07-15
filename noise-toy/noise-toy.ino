
//buzzer 1 pins
const int POT_PIN_1 = 0;
const int BUZZER1 = 4;
const int GREEN_LED_1 = 8;
const int YELLOW_LED_1 = 9;
const int RED_LED_1 = 10;

//buzzer 2 pins
const int POT_PIN_2 = 1;
const int BUZZER2 = 7;
const int GREEN_LED_2 = 11;
const int YELLOW_LED_2 = 12;
const int RED_LED_2 = 13;

//Potentiometer values get read between 0 and 1023
const int POT_MIN_READING = 0;
const int POT_MAX_READING = 1023;

//Buzzer tone limits - Passive buzzers and active buzzers
const int ACTIVE_MIN_TONE = 100;
const int ACTIVE_MAX_TONE = 10000;

const int PASSIVE_MIN_TONE = 100;
const int PASSIVE_MAX_TONE = 3000;

//Values to trigger LEDs
const int LOW_FREQ = 200;
const int MED_FREQ = 450;
const int HIGH_FREQ = 800;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER1,OUTPUT);
  pinMode(BUZZER2,OUTPUT);
  pinMode(GREEN_LED_1,OUTPUT);
  pinMode(YELLOW_LED_1,OUTPUT);
  pinMode(RED_LED_1,OUTPUT);
  pinMode(GREEN_LED_2,OUTPUT);
  pinMode(YELLOW_LED_2,OUTPUT);
  pinMode(RED_LED_2,OUTPUT);
}

void loop() {
  //Speaker 1
  buzz(POT_PIN_1, BUZZER1, ACTIVE_MIN_TONE, ACTIVE_MAX_TONE);
  
  writeLedStatus(POT_PIN_1, GREEN_LED_1, LOW_FREQ);

  writeLedStatus(POT_PIN_1, YELLOW_LED_1, MED_FREQ);

  writeLedStatus(POT_PIN_1, RED_LED_1, HIGH_FREQ);
  
  //Speaker 2
  buzz(POT_PIN_2, BUZZER2, PASSIVE_MIN_TONE, PASSIVE_MAX_TONE);

  writeLedStatus(POT_PIN_2, GREEN_LED_2, LOW_FREQ);

  writeLedStatus(POT_PIN_2, YELLOW_LED_2, MED_FREQ);

  writeLedStatus(POT_PIN_2, RED_LED_2, HIGH_FREQ);
  
}

void writeLedStatus(int potPin, int ledPin, int freqThreshold){
  if (analogRead(potPin) > freqThreshold)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}

void buzz(int potPin, int buzzerPin,int minTone, int maxTone){
  tone(buzzerPin, map(analogRead(potPin), POT_MIN_READING, POT_MAX_READING, minTone, maxTone));
  delay(10);
  noTone(buzzerPin);
}

