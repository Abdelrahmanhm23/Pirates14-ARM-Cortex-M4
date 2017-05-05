#include <SPI.h>
const int slaveSelectPin = 10;

void setup() {

  pinMode(slaveSelectPin, OUTPUT);
  SPI.begin();

}
 //SPI.SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode);
void loop() {
// SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode);
   digitalWrite(slaveSelectPin, LOW);
  SPI.transfer(0x05);
  digitalWrite(slaveSelectPin, HIGH);
  while(1);
}
