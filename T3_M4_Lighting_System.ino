/*
 * VERSION_1 of the T3_Lighting_System. Any problems then drop me a line @ t3buildersclub@gmail.com and I'll help you fix any problems. The code works however is very sloppy and can
 * be written a lot better which will be the next update.
*/

#include <Adafruit_NeoPixel.h>
#define LED_PIN     9, 6, 5 //Check these for any troubleshooting needed, make sure the correct pixels are in the correct places.
#define LED_COUNT  9, 16, 24 
#define BRIGHTNESS 255, 255, 255 //Adjust brightness here and in the sketch as you require.
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip_s = Adafruit_NeoPixel(7, 9, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip_l = Adafruit_NeoPixel(16, 6, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip_m = Adafruit_NeoPixel(24, 5, NEO_GRBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:

void setup() { //The start up sequence is a colour wipe of Red, Orange, Yellow, White around all of the neopixels - setup only happens once so all colours go round the pixels once and then into the loop.

/*strip_l = Large Eye
  strip_s = Small Eye
  strip_m = Main Eye
*/

  //Startup Light Sequence
  strip_l.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip_l.show();            // Turn OFF all pixels ASAP
  strip_l.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip_m.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip_m.show();            // Turn OFF all pixels ASAP
  strip_m.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip_s.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip_s.show();            // Turn OFF all pixels ASAP
  strip_s.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  // Fill along the length of the strip in various colors...
  colorWipe_l(strip_l.Color(255,   0,   0)     , 50); // Red
  colorWipe_l(strip_l.Color(  255, 90,   0)     , 50); // Orange
  colorWipe_l(strip_l.Color(  255, 225,   0)     , 50); // Yellow
  colorWipe_l(strip_l.Color(  0, 0, 0,   255)     , 50); // White*/
}
void loop() { 
  int now = millis();
  pulseWhite(5);
  mainEye();

}

//Color Wipe
//All Eye's Start up Sequence
void colorWipe_l(uint32_t color, int wait) { //Small Eye
  for(int i=0; i<strip_s.numPixels(); i++) { // For each pixel in strip...
    strip_s.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    delay(wait);                           //  Pause for a moment
  }
  for(int i=0; i<strip_l.numPixels(); i++){ //Large Eye
    strip_l.setPixelColor(i, color);
  }
    for(int i=0; i<strip_m.numPixels(); i++){ //Main Eye
    strip_m.setPixelColor(i, color);
    strip_s.show();
    strip_l.show();
    strip_m.show();
  }
}
//PulseWhite
void pulseWhite(uint8_t wait) {
  for(int j=0; j<256; j++) { // Ramp up from 0 to 255
    // Colours for pulse - Colour 
    strip_l.fill(strip_l.Color(255, 0, 0,  j));
    strip_s.fill(strip_s.Color(255, 0, 0,  j));
    strip_l.show();
    strip_s.show();
    millis();
  }
//Color 2
  for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
    strip_l.fill(strip_l.Color(255, 90,0, j));
    strip_s.fill(strip_l.Color(255, 90,0, j));
    strip_l.show();
    strip_s.show();
    millis();
  }
}
//Main Eye Color Changing
//Current colour is set to blue and white. Change the values for different colours.
void mainEye(){
int timer = random(500)+50; // between 1/5 second and 1 second
strip_m.setPixelColor(0,0,0,255,0);
strip_m.setPixelColor(1,255,255,255,50);
strip_m.setPixelColor(2,0,0,255,0);
strip_m.setPixelColor(3,255,255,255,50);
strip_m.setPixelColor(4,0,0,255,0);
strip_m.setPixelColor(5,255,255,255,50);
strip_m.setPixelColor(6,0,0,255,0);
strip_m.setPixelColor(7,255,255,255,50);
strip_m.setPixelColor(8,0,0,255,0);
strip_m.setPixelColor(9,255,255,255,50);
strip_m.setPixelColor(10,0,0,255,0);
strip_m.setPixelColor(11,255,255,255,50);
strip_m.setPixelColor(12,0,0,255,0);
strip_m.setPixelColor(13,255,255,255,50);
strip_m.setPixelColor(14,0,0,255,0);
strip_m.setPixelColor(15,255,255,255,50);
strip_m.setPixelColor(16,0,0,255,0);
strip_m.setPixelColor(17,255,255,255,50);
strip_m.setPixelColor(18,0,0,255,0);
strip_m.setPixelColor(19,255,255,255,50);
strip_m.setPixelColor(20,0,0,255,0);
strip_m.setPixelColor(21,255,255,255,50);
strip_m.setPixelColor(22,0,0,255,0);
strip_m.setPixelColor(23,255,255,255,50);
delay(timer);

strip_m.show();

strip_m.setPixelColor(0,255,255,255,0);
strip_m.setPixelColor(1,0,0,255,0);
strip_m.setPixelColor(2,255,255,255,0);
strip_m.setPixelColor(3,0,0,255,0);
strip_m.setPixelColor(4,255,255,255,0);
strip_m.setPixelColor(5,0,0,255,0);
strip_m.setPixelColor(6,255,255,255,0);
strip_m.setPixelColor(7,0,0,255,0);
strip_m.setPixelColor(8,255,255,255,0);
strip_m.setPixelColor(9,0,0,255,0);
strip_m.setPixelColor(10,255,255,255,0);
strip_m.setPixelColor(11,0,0,255,0);
strip_m.setPixelColor(12,255,255,255,0);
strip_m.setPixelColor(13,0,0,255,0);
strip_m.setPixelColor(14,255,255,255,0);
strip_m.setPixelColor(15,0,0,255,0);
strip_m.setPixelColor(16,255,255,255,0);
strip_m.setPixelColor(17,0,0,255,0);
strip_m.setPixelColor(18,255,255,255,0);
strip_m.setPixelColor(19,0,0,255,0);
strip_m.setPixelColor(20,255,255,255,0);
strip_m.setPixelColor(21,0,0,255,0);
strip_m.setPixelColor(22,255,255,255,0);
strip_m.setPixelColor(23,0,0,255,0);

delay(timer);
strip_m.show();
}