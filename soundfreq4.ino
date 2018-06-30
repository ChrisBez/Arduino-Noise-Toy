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
  
  
  if (sensorValue1 > LOW_FREQ)
    digitalWrite(greenLED1, HIGH);
  else
    digitalWrite(greenLED1, LOW);
    
  if (sensorValue1 > MED_FREQ)
    digitalWrite(yellowLED1, HIGH);
  else
    digitalWrite(yellowLED1, LOW);  
  
  if (sensorValue1 > HIGH_FREQ)
    digitalWrite(redLED1, HIGH);
  else
    digitalWrite(redLED1, LOW);
  
  //Speaker 2
  sensorValue2 = analogRead(A1);
  Serial.println(sensorValue2);
  mapValue2 = map(sensorValue2, 0, 1023, 100, 3000);
  Serial.println(mapValue2);
  tone(BUZZER2, mapValue2);
  delay(10);
  noTone(BUZZER2);

  if (sensorValue2 > LOW_FREQ)
    digitalWrite(greenLED2, HIGH);
  else
    digitalWrite(greenLED2, LOW);
    
  if (sensorValue2 > MED_FREQ)
    digitalWrite(yellowLED2, HIGH);
  else
    digitalWrite(yellowLED2, LOW);  
  
  if (sensorValue2 > HIGH_FREQ)
    digitalWrite(redLED2, HIGH);
  else
    digitalWrite(redLED2, LOW);
  
}
