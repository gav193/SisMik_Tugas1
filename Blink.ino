#define LED 14 // set LED pin to D2

int onTime = 800;  // Time LED stays ON
int offTime = 1600; // Time LED stays OFF

void setup() {
  // set LED as output
  pinMode(LED, OUTPUT);
}

void loop() {
  
  digitalWrite(LED, HIGH);
  delay(onTime); // LED set to HIGH for 800ms
  
  digitalWrite(LED, LOW);
  delay(offTime); // LED set to LOW for 1600ms

  // period = 2400ms
  // duty cycle = 800 / 2400 = 33.3%
}
