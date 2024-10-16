#define LED 14
#define BUTTON1 5
#define BUTTON2 18
#define BUTTON3 19

int sel = 0; // selector for boolean operation types

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP); 
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP); 
  digitalWrite(LED, LOW);
  Serial.begin(9600);

  // Print initial menu
  Serial.println("Select a mode:");
  Serial.println("1 = AND");
  Serial.println("2 = OR");
  Serial.println("3 = XOR");
  Serial.println("==============================");
}

int readButton(int pin) { // button read with debounce
  int state = digitalRead(pin);
  int stableState = state;
  int now = millis(); // read current time

  while (millis() - now < 50) { // 50ms debounce interval
    state = digitalRead(pin);
    if (state != stableState) { // reset debounce timer if state changes
      stableState = state;
      now = millis();
    }
  }
  return !stableState; // return the stable state
}

void loop() {
  int a = 0;
  int b = 0;
  int c = 0;
  int sum = 0; // declare for selection
  
  switch (sel) {
    case 1:
      Serial.println("AND operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      Serial.print("Button states: ");
      Serial.print(a);
      Serial.print(", ");
      Serial.print(b);
      Serial.print(", ");
      Serial.print(c);
      Serial.print(" | Sum: ");
      Serial.println(sum);
      if (sum==3) {
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
      while (Serial.available() == 0) { // wait for next input
        // do nothing
      }
      sel = Serial.parseInt(); // update mode selection
      break;

    case 2:
      Serial.println("OR operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      Serial.print("Button states: ");
      Serial.print(a);
      Serial.print(", ");
      Serial.print(b);
      Serial.print(", ");
      Serial.print(c);
      Serial.print(" | Sum: ");
      Serial.println(sum);
      if (sum>0) {
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED,LOW);
      }
      while (Serial.available() == 0) { // wait for next input
        // do nothing
      }
      sel = Serial.parseInt(); // Update mode selection
      break;

    case 3:
      Serial.println("XOR operation selected");
      a = readButton(BUTTON1);
      b = readButton(BUTTON2);
      c = readButton(BUTTON3);
      sum = a+b+c;
      Serial.print("Button states: ");
      Serial.print(a);
      Serial.print(", ");
      Serial.print(b);
      Serial.print(", ");
      Serial.print(c);
      Serial.print(" | Sum: ");
      Serial.println(sum);
      if (sum%2==1) {
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
      while (Serial.available() == 0) { // wait for next input
        // do nothing
      }
      sel = Serial.parseInt(); // Update mode selection
      break;

    case 0:
      Serial.println("Select a mode:");
      Serial.println("1 = AND");
      Serial.println("2 = OR");
      Serial.println("3 = XOR");
      Serial.println("==============================");
      while (Serial.available() == 0) { // Wait for input
        // do nothing
      }
      sel = Serial.parseInt(); // Update mode selection
      break;
      
    default:
      Serial.println("Invalid selection. Please select 1, 2, or 3.");
      sel = 0; // Reset sel to 0 if invalid selection is made
      break;
  }

  delay(500); // Small delay to avoid rapid printing
}
