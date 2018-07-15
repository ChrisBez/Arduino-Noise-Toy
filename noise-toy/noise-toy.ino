
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

//Buzzer tone limits: Passive buzzers and active buzzers
const int ACTIVE_MIN_TONE = 100;
const int ACTIVE_MAX_TONE = 10000;

const int PASSIVE_MIN_TONE = 100;
const int PASSIVE_MAX_TONE = 3000;

//Values to trigger LEDs
const int LOW_FREQ = 200;
const int MED_FREQ = 450;
const int HIGH_FREQ = 800;


const int LED_COUNT = 6;
const int LED_PROPS = 3;


const int LED_PIN = 0;
const int LED_POT_PIN = 1;
const int LED_FREQ = 2;

//Matrix used in LED Status loop
const int LED_MATRIX[LED_COUNT][LED_PROPS] = {
 
  {GREEN_LED_1,   POT_PIN_1,  LOW_FREQ  },
 
  {YELLOW_LED_1,  POT_PIN_1,  MED_FREQ  },
 
  {RED_LED_1,     POT_PIN_1,  HIGH_FREQ },

  {GREEN_LED_2,   POT_PIN_2,  LOW_FREQ  },
 
  {YELLOW_LED_2,  POT_PIN_2,  MED_FREQ  },
 
  {RED_LED_2,     POT_PIN_2,  HIGH_FREQ }
 
};


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
    
  //Speaker 2
  buzz(POT_PIN_2, BUZZER2, PASSIVE_MIN_TONE, PASSIVE_MAX_TONE);

  //Test each LED for activation and light them up
  for (int i = 0; i < LED_COUNT; i++){
    if (analogRead(LED_MATRIX[i][LED_POT_PIN]) > LED_MATRIX[i][LED_FREQ])
      digitalWrite(LED_MATRIX[i][LED_PIN], HIGH);
    else
      digitalWrite(LED_MATRIX[i][LED_PIN], LOW);
  }
}

void buzz(int potPin, int buzzerPin,int minTone, int maxTone){
  tone(buzzerPin, map(analogRead(potPin), POT_MIN_READING, POT_MAX_READING, minTone, maxTone));
  delay(10);
  noTone(buzzerPin);
}

