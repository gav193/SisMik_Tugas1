
#define LED 14
#define BUTTON1 5  
#define BUTTON2 18 
#define BUTTON3 19 

int ledState = 0;  
int blinkState = 0; 

void IRAM_ATTR turnOnLED() {
  ledState = 1;
  digitalWrite(LED, HIGH);
  blinkState = 0;
}

void IRAM_ATTR turnOffLED() {
  ledState = 0;
  digitalWrite(LED, LOW);
  blinkState = 0;
}

void IRAM_ATTR blinkLED() {
  blinkState = 1;
}

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);  

  // Button pins
  pinMode(BUTTON1, INPUT_PULLUP); 
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  // Attach interrupts
  attachInterrupt(digitalPinToInterrupt(BUTTON1), turnOnLED, FALLING);  
  attachInterrupt(digitalPinToInterrupt(BUTTON2), turnOffLED, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON3), blinkLED, FALLING);
}

void loop() {
  if (blinkState) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED,LOW);
    delay(500);
  } else { 
      if (ledState) {
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
  }
} 
