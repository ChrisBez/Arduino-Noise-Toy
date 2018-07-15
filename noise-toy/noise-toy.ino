
//set 1 pins
const int BUZZER1 = 4;
const int greenLED1 = 8;
const int yellowLED1 = 9;
const int redLED1 = 10;


//set 2 pins
const int BUZZER2 = 7;
const int greenLED2 = 11;
const int yellowLED2 = 12;
const int redLED2 = 13;

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
  pinMode(greenLED1,OUTPUT);
  pinMode(yellowLED1,OUTPUT);
  pinMode(redLED1,OUTPUT);
  pinMode(greenLED2,OUTPUT);
  pinMode(yellowLED2,OUTPUT);
  pinMode(redLED2,OUTPUT);
}

void loop() {
  //Speaker 1
  sensorValue1 = analogRead(A0);
  Serial.println(sensorValue1);
  mapValue1 = map(sensorValue1, POT_MIN_READING, POT_MAX_READING, ACTIVE_MIN_TONE, ACTIVE_MAX_TONE);
  Serial.println(mapValue1);
  tone(BUZZER1, mapValue1);
  delay(10);
  noTone(BUZZER1);
  
  writeLedStatus(sensorValue1, greenLED1, LOW_FREQ);

  writeLedStatus(sensorValue1, yellowLED1, MED_FREQ);

  writeLedStatus(sensorValue1, redLED1, HIGH_FREQ);
  
  //Speaker 2
  sensorValue2 = analogRead(A1);
  Serial.println(sensorValue2);
  mapValue2 = map(sensorValue2, POT_MIN_READING, POT_MAX_READING, PASSIVE_MIN_TONE, PASSIVE_MAX_TONE);
  Serial.println(mapValue2);
  tone(BUZZER2, mapValue2);
  delay(10);
  noTone(BUZZER2);

  writeLedStatus(sensorValue2, greenLED2, LOW_FREQ);

  writeLedStatus(sensorValue2, yellowLED2, MED_FREQ);

  writeLedStatus(sensorValue2, redLED2, HIGH_FREQ);
  
}

void writeLedStatus(int sensor, int led, int freq){
    if (sensor > freq)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);
}



