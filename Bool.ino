#define LED 2
#define BUTTON1 5
#define BUTTON2 18
#define BUTTON3 19

int sel = 0; // selector for boolean operation types

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

int readButton(int pin) { // button read with debounce
  int state = digitalRead(pin);
  int stableState = state;
  int now = millis(); // read current time

  while (millis() - now < 50) { // 50ms debounce interval
    state = digitalRead(pin);
    if ( state != stableState) { // reset debounce timer if state changes
      stableState = state;
      now = millis();
    }
  }
  return state; // returns if button is consistently the same state for 50ms
}

void loop() {
  int a = 0;
  int b = 0;
  int c = 0;
  int sum = 0; // declare for selection
  
  if (Serial.available() > 0) {
    sel = Serial.parseInt(); // check serial monitor for integer input
  }

  switch (sel) {
    case 1 :
      Serial.println("AND operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      if (sum == 3) { // all button pressed (AND triggered)
        digitalWrite(LED, HIGH);  
      } else {
        digitalWrite(LED, LOW);  
      }
      break;

    case 2 :
      Serial.println("OR operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      if (sum>0) { // at least 1 button (OR triggered)
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
      break;
    case 3 : 
      Serial.println("XOR operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      if (sum%2 == 1) { // odd number of buttons pressed (XOR triggered)
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
      break;
    default : // other cases
      Serial.println("Select a mode:");
      Serial.println("1 = AND");
      Serial.println("2 = OR");
      Serial.println("3 = XOR");
      Serial.println("==============================");
      digitalWrite(LED, LOW);
      break;    
  }
}
