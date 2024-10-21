#define LED 14 // set LED pin to D2

int onTime = 1000;  // Time LED stays ON
int offTime = 2000; // Time LED stays OFF

void setup() {
  // set LED as output
  pinMode(LED, OUTPUT);
}

void loop() {
  
  digitalWrite(LED, HIGH);
  delay(onTime); // LED set to HIGH for 1000ms
  
  digitalWrite(LED, LOW);
  delay(offTime); // LED set to LOW for 2000ms

  // period = 3000ms
  // duty cycle = 1000 / 3000 = 33.3%
}
