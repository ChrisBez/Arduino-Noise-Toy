int BUZZER1 = 4;
int sensorValue1 = 0;
int mapValue1 = 0;

int BUZZER2 = 7;
int sensorValue2 = 0;
int mapValue2 = 0;



void setup() {
  Serial.begin(9600);
  pinMode(BUZZER1,OUTPUT);
  pinMode(BUZZER2,OUTPUT);
}

void loop() {
  sensorValue1 = analogRead(A0);
  Serial.println(sensorValue1);
  mapValue1 = map(sensorValue1, 0, 1023, 100, 10000);
  Serial.println(mapValue1);
  tone(BUZZER1, mapValue1);
  delay(10);
  noTone(BUZZER1);

  sensorValue2 = analogRead(A1);
  Serial.println(sensorValue2);
  mapValue2 = map(sensorValue2, 0, 1023, 100, 3000);
  Serial.println(mapValue2);
  tone(BUZZER2, mapValue2);
  delay(10);
  noTone(BUZZER2);
}
