#include <Arduino.h>
#include <SoftwareSpiMaster.h>

// Slave select (chip select) pin
const uint8_t SLAVE_SELECT = 5;

SoftwareSpiMaster spi;

void setup() {
  spi.begin(12, 13, 4);
  
  // Chip Select
  pinMode(5, OUTPUT);
}

void loop() {
  uint8_t readValue;
  
  // Read one byte from client by sending dummy data
  digitalWrite(SLAVE_SELECT, LOW);
  readValue = spi.transfer(0xFF);
  digitalWrite(SLAVE_SELECT, HIGH);
  
  delay(100);
}