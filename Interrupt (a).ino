#define LED 14
#define BUTTON1 5  // Tombol 1 untuk menyalakan LED
#define BUTTON2 18 // Tombol 2 untuk mematikan LED

int ledState = 0; // Status LED (0 = mati, 1 = menyala)

void IRAM_ATTR turnOnLED() {
  ledState = 1;  // Set status LED menyala
  digitalWrite(LED, HIGH); // Nyalakan LED
}

void IRAM_ATTR turnOffLED() {
  ledState = 0;  // Set status LED mati
  digitalWrite(LED, LOW); // Matikan LED
}

void setup() {
  pinMode(LED, OUTPUT); // Set pin LED sebagai output
  digitalWrite(LED, LOW);  // Inisialisasi LED mati

  // Set pin tombol sebagai input dengan internal pull-up
  pinMode(BUTTON1, INPUT_PULLUP); 
  pinMode(BUTTON2, INPUT_PULLUP);

  // Pasang interupsi pada tombol
  attachInterrupt(digitalPinToInterrupt(BUTTON1), turnOnLED, FALLING);  
  attachInterrupt(digitalPinToInterrupt(BUTTON2), turnOffLED, FALLING);
}

void loop() {
  // Tidak perlu ada kode tambahan di loop, karena kontrol dilakukan oleh interupsi
  // LED akan menyala dan mati sesuai dengan tombol
}
