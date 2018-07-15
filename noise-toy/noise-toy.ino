
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


//variables
int sensorValue1 = 0;
int mapValue1 = 0;

int sensorValue2 = 0;
int mapValue2 = 0;

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
  sensorValue1 = analogRead(POT_PIN_1);
  Serial.println(sensorValue1);
  mapValue1 = map(sensorValue1, POT_MIN_READING, POT_MAX_READING, ACTIVE_MIN_TONE, ACTIVE_MAX_TONE);
  Serial.println(mapValue1);
  tone(BUZZER1, mapValue1);
  delay(10);
  noTone(BUZZER1);
  
  writeLedStatus(sensorValue1, GREEN_LED_1, LOW_FREQ);

  writeLedStatus(sensorValue1, YELLOW_LED_1, MED_FREQ);

  writeLedStatus(sensorValue1, RED_LED_1, HIGH_FREQ);
  
  //Speaker 2
  sensorValue2 = analogRead(POT_PIN_2);
  Serial.println(sensorValue2);
  mapValue2 = map(sensorValue2, POT_MIN_READING, POT_MAX_READING, PASSIVE_MIN_TONE, PASSIVE_MAX_TONE);
  Serial.println(mapValue2);
  tone(BUZZER2, mapValue2);
  delay(10);
  noTone(BUZZER2);

  writeLedStatus(sensorValue2, GREEN_LED_2, LOW_FREQ);

  writeLedStatus(sensorValue2, YELLOW_LED_2, MED_FREQ);

  writeLedStatus(sensorValue2, RED_LED_2, HIGH_FREQ);
  
}

void writeLedStatus(int sensor, int led, int freq){
    if (sensor > freq)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);
}

void buzz(int potValue, int buzzerPin,int minTone, int maxTone){
  Serial.println(potValue);
  tone(buzzerPin, map(potValue, POT_MIN_READING, POT_MAX_READING, minTone, maxTone));
  delay(10);
  noTone(buzzerPin);
}

