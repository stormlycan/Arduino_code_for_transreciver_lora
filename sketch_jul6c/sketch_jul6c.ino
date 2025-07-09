#include <SoftwareSerial.h>

#define M0_PIN 2
#define M1_PIN 3

SoftwareSerial E22(5, 4); // E22 TX → D5, RX ← D4

void setup() {
  Serial.begin(9600);
  E22.begin(9600);  // or 115200 depending on module

  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);

  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, HIGH);
  delay(100);

  Serial.println("E22 AT mode initialized...");

  sendCommand("AT");
}

void loop() {
  if (Serial.available()) {
    String userCmd = Serial.readStringUntil('\n');
    userCmd.trim(); // Remove trailing newline or spaces

    if (userCmd.length() > 0) {
      sendCommand(userCmd);
    }
  }

  // Optionally check if E22 has unsolicited responses
  if (E22.available()) {
    Serial.print("<< ");
    while (E22.available()) {
      Serial.write(E22.read());
    }
    Serial.println();
  }
}


void sendCommand(String cmd) {
  Serial.print(">> ");
  Serial.println(cmd);
  E22.print(cmd + "\r\n");

  unsigned long start = millis();
  while (millis() - start < 1000) {
    while (E22.available()) {
      Serial.write(E22.read());
    }
  }
}
