# SoftwareSpiMaster
A software SPI implementation for Arduino to run a SPI master on arbitrary pins.

## Usage
Just like the Arduino SPI library, the library has a easy to use interface:

Main functions:
```
//Start a SPI master using the given pins
void begin(uint8_t clk, uint8_t mosi, uint8_t miso);

//Stops the SPI master
void end();

// Transfer a single byte to the slave
uint8_t transfer(uint8_t value);

//Transfer a buffer to the slave
void transfer(const uint8_t* sendBuf, uint8_t* recBuf, uint16_t size);
```

## Example
```
#include <Arduino.h>
#include <SoftwareSpiMaster.h>

// Slave select (chip select) pin
const uint8_t SLAVE_SELECT = P_SS;

SoftwareSpiMaster spi;

void setup() {
  spi.begin(P_CK, P_MOSI, P_MISO);
  
  // Chip Select
  pinMode(P_SS, OUTPUT);
}

void loop() {
  uint8_t readValue;
  
  // Read one byte from client by sending dummy data
  digitalWrite(SLAVE_SELECT, LOW);
  readValue = spi.transfer(0xFF);
  digitalWrite(SLAVE_SELECT, HIGH);
  
  delay(100);
}
```
