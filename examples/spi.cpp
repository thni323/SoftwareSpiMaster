#include <Arduino.h>
#include <SoftwareSpiMaster.h>

// Slave select (chip select) pin
const uint8_t SLAVE_SELECT = PIN_SS;

SoftwareSpiMaster spi;

void setup() {
  // Start spi
  spi.begin(PIN_CLK, PIN_MOSI, PIN_MISO);
  
  // Slave select acting as output
  pinMode(PIN_SS, OUTPUT);
}

void loop() {
  // - Read one byte from slave by sending dummy data -
  // Activate spi slave via chip select
  digitalWrite(SLAVE_SELECT, LOW);
  // Transfer a single (dummy) byte
  uint8_t readValue;
  readValue = spi.transfer(0xFF);
  // Deactivate spi slave via chip select
  digitalWrite(SLAVE_SELECT, HIGH);
  
  // - Transfer a buffer to the client - 
  // Send and receive buffer initialization
  uint8_t sendBuf[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
  uint8_t recBuf[4];
  // Activate spi slave via chip select
  digitalWrite(SLAVE_SELECT, LOW);
  // Transfer sendBuf to client, received bytes get stored in recBuf
  spi.transfer(sendBuf, recBuf, 4);
  // Deactivate spi slave via chip select
  digitalWrite(SLAVE_SELECT, HIGH);
  
  delay(100);
}
