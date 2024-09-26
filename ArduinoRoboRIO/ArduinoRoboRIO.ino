#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);

#define SCK_PIN   13
#define MISO_PIN  12
#define MOSI_PIN  11
#define SS_PIN    10

#define UL unsigned long
#define US unsigned short

void SlaveInit(void) {
  pinMode(SCK_PIN, INPUT);
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SS_PIN, INPUT);
}


unsigned short Read2Bytes(void) {
    union {
    double svar;
    byte c[8];
  } w;
  
  while(!(SPSR & (1<<SPIF)));
  w.c[7] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[6] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[5] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[4] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[3] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[2] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[1] = SPDR;
  while(!(SPSR & (1<<SPIF)));
  w.c[0] = SPDR;

  return (w.svar); //send received value back
}

void setup() {
  Serial.begin(9600);
  SlaveInit();
  delay(10);
  strip.begin();
  strip.show();
}

void loop() {
    unsigned short word1;

    while (digitalRead(SS_PIN)==1) {} // wait until SlaveSelect goes low (active)
    SPCR = (1<<SPE)|(0<<DORD)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA)|(0<<SPR1)|(1<<SPR0);
    word1 = Read2Bytes();
    SPCR = (0<<SPE)|(0<<DORD)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA)|(0<<SPR1)|(1<<SPR0);

    if (word1 == 0) {
    uint32_t green = strip.Color(0, 64, 0, 64);
    strip.fill(green, 0, 10);
    strip.show();
    }
    else if (word1 == 1) {
      uint32_t red = strip.Color(64, 0, 0, 64);
    strip.fill(red, 0, 10);
    strip.show();
    }
}

    
    
  

}
