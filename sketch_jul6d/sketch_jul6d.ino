#include <SoftwareSerial.h>

#define M0_PIN 2
#define M1_PIN 3

SoftwareSerial E22(5, 4);  // E22 TX → D5, RX ← D4

void setup() {
  Serial.begin(9600);
  E22.begin(9600);

  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);

  // NORMAL mode: M0 = LOW, M1 = LOW
  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, LOW);
  delay(100);

  Serial.println("E22 Receiver Started...");
}

void loop() {
  if (E22.available()) {
    String received = E22.readStringUntil('\n');
    Serial.println("Received: " + received);
  }
}
