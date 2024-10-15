#define LED 2
#define BUTTON_ON 5  // Button to turn LED ON
#define BUTTON_OFF 18 // Button to turn LED OFF

volatile bool ledState = false;   // Current state of the LED (false = OFF, true = ON)
volatile bool blinkMode = false;  // Whether we should enter the blink mode or not

// Interrupt Service Routine for turning ON the LED
void IRAM_ATTR turnOnLED() {
  if (!blinkMode) {  // Only change the LED state if not in blink mode
    ledState = true;
    digitalWrite(LED, HIGH);
  }
}

// Interrupt Service Routine for turning OFF the LED
void IRAM_ATTR turnOffLED() {
  if (!blinkMode) {  // Only change the LED state if not in blink mode
    ledState = false;
    digitalWrite(LED, LOW);
  }
}

// Function to blink the LED when both buttons are pressed
void blinkLED() {
  while (blinkMode) {
    digitalWrite(LED, HIGH);
    delay(500);  // LED ON for 500 ms
    digitalWrite(LED, LOW);
    delay(500);  // LED OFF for 500 ms
  }
}

// Interrupt Service Routine to handle both buttons pressed simultaneously (activates blink mode)
void IRAM_ATTR handleBothPressed() {
  if (digitalRead(BUTTON_ON) == LOW && digitalRead(BUTTON_OFF) == LOW) { // Both buttons pressed
    blinkMode = true;  // Activate blink mode
    blinkLED();        // Start blinking
  } else {
    blinkMode = false;  // Deactivate blink mode
    if (ledState) {
      digitalWrite(LED, HIGH);  // Restore LED state after exiting blink mode
    } else {
      digitalWrite(LED, LOW);
    }
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_ON, INPUT_PULLUP);  // Button to turn LED ON
  pinMode(BUTTON_OFF, INPUT_PULLUP); // Button to turn LED OFF
  
  // Attach interrupt for BUTTON_ON to turn on LED (on falling edge)
  attachInterrupt(digitalPinToInterrupt(BUTTON_ON), turnOnLED, FALLING);

  // Attach interrupt for BUTTON_OFF to turn off LED (on falling edge)
  attachInterrupt(digitalPinToInterrupt(BUTTON_OFF), turnOffLED, FALLING);
  
  // Attach interrupt to detect when both buttons are pressed
  attachInterrupt(digitalPinToInterrupt(BUTTON_ON), handleBothPressed, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_OFF), handleBothPressed, CHANGE);
}

void loop() {
  // The main loop does nothing, everything is handled by interrupts
}
