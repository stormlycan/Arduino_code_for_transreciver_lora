#include <SoftwareSerial.h>

#define M0_PIN 2
#define M1_PIN 3

SoftwareSerial E22(5, 4);  // E22 TX → D5, RX ← D4

void setup() {
  Serial.begin(9600);
  E22.begin(9600); // Match with module baud rate

  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);

  // NORMAL mode: M0 = LOW, M1 = LOW
  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, LOW);
  delay(100);

  Serial.println("E22 Transmitter Started...");
}

void loop() {
  String msg = "Hello from storm!";
  E22.println(msg);
  Serial.println("Sent: " + msg);
  delay(2000);  // Send every 2 seconds
}
