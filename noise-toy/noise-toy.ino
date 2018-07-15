int BUZZER1 = 4;
int sensorValue1 = 0;
int mapValue1 = 0;
int greenLED1 = 8;
int yellowLED1 = 9;
int redLED1 = 10;

int BUZZER2 = 7;
int sensorValue2 = 0;
int mapValue2 = 0;
int greenLED2 = 11;
int yellowLED2 = 12;
int redLED2 = 13;


int LOW_FREQ = 200;
int MED_FREQ = 450;
int HIGH_FREQ = 800;



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
  mapValue1 = map(sensorValue1, 0, 1023, 100, 10000);
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
  mapValue2 = map(sensorValue2, 0, 1023, 100, 3000);
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

