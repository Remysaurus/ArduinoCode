
#include <SPI.h>
void setup() {
  
  SPI.begin();
  

  SPI.beginTransaction(SPISettings(100, MSBFIRST, SPI_MODE2));
  Serial.begin(100);
  pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10, LOW);
  SPI.transfer(3);
  digitalWrite(10, HIGH);
  delay(1000);
  

}
