#include <SoftwareSerial.h>

#define M0_PIN 2
#define M1_PIN 3

// E22 TX → D5, RX ← D4
SoftwareSerial E22(5, 4);

void setup() {
  Serial.begin(9600);    // For Serial Monitor
  E22.begin(9600);       // Match E22 config

  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);

  // Set to NORMAL mode for transmit/receive
  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, LOW);
  delay(100);

  Serial.println("E22 Chat Mode Ready.");
  Serial.println("Type a message and press Enter.");
}

void loop() {
  // 1. Send from Serial Monitor → E22
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    if (msg.length() > 0) {
      E22.println(msg);
      Serial.println("You: " + msg);
    }
  }

  // 2. Receive from E22 → Serial Monitor
  if (E22.available()) {
    String incoming = E22.readStringUntil('\n');
    incoming.trim();
    if (incoming.length() > 0) {
      Serial.println("Friend: " + incoming);
    }
  }
}
