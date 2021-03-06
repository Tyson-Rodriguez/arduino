
//RGBW demo cw coleman demo 2

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

//set up variables

int red = 100;  int green = 200; int blue = 50; int white = 25;
int d = 100;
void loop() {
  ///////////////////////////////////
  red = 100; green = 0; blue = 0; white = 0; d = 100;
  ccw(red,green,blue,white,d);
  delay(10);
  //////////////////////////////////
   red = 0; green = 0; blue = 0; white = 100; d = 10;
  cw(red,green,blue,white,d);
   //////////////////////////////////
   red = 0; green = 0; blue = 100; white = 0; d = 10;
  ccw(red,green,blue,white,d);
}


void ccw(int  r,int g,int b,int w, int delayVal){

int j;

  for(j = 0; j < 16 ; j++){
          strip.setPixelColor(j, strip.Color(r,g,b,w ));
          delay(delayVal);
           strip.show();         
  }
    
}

void cw(int  r,int g,int b,int w, int delayVal){

int j;

  for(j = 15; j>= 0 ; j--){
          strip.setPixelColor(j, strip.Color(r,g,b,w ));
          delay(delayVal);
           strip.show();         
  }
    
}
