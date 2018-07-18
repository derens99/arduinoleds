#include <FastLED.h>

#define DATA_PIN 6
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 288
#define BRIGHTNESS 96

CRGB leds[NUM_LEDS];


void setup() {
  delay(3000); // initial delay of a few seconds is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}
// switches off all LEDs
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}
// switches on all LEDs. Each LED is shown in random color.
// numIterations: indicates how often LEDs are switched on in random colors
// delayTime: indicates for how long LEDs are switched on.
void showProgramRandom(int numIterations, long delayTime) {
  for (int iteration = 0; iteration < numIterations; ++iteration) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(),255,255); // hue, saturation, value
    }
    FastLED.show();
    delay(delayTime);
  }
}
// Shifts a single pixel from the start of strip to the end.
// crgb: color of shifted pixel
// delayTime: indicates how long the pixel is shown on each LED
void showProgramShiftSinglePixel(CRGB crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

void derenLights(long delayTime){
  int counter = 0;
     for (int i = 0; i < NUM_LEDS; ++i) {
      if(counter == 255){
        counter = 0;
      }
      leds[i] = CHSV(counter++, 255, 255);
      FastLED.show();
      delay(delayTime);
      leds[i] = CHSV(counter, 255, 255);
  }
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  
}

void derenLights3(long delayTime){
  int counter = 0;
     for (int i = 0; i < NUM_LEDS; ++i) {
      if(counter == 255){
        counter = 0;
      }
      leds[i] = CHSV(counter++, 255, 255);
      FastLED.show();
      delay(delayTime);
      
  }
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  
}

void derenLights2(long delayTime){
  int counter = 0;
  while(counter <= NUM_LEDS){
    int location = random(0, NUM_LEDS);
    CRGB color = CHSV(random(1, 255), 255, 255);
    if(!leds[location]){
      leds[location] = CHSV(random(1, 255), 255, 255);
    }
    FastLED.show();
    delay(delayTime);
    counter++;
  }
}

void rainbow3(long delayTime){
  int location = 0;
  int counter = 0;
  for (int i = 0; i < NUM_LEDS-10; ++i) {
    if(counter == 255){
        counter = 0;
      }
      counter++;
    for(int j = 0; j < 10; j++){
      leds[i+j] =  CHSV(counter, 255, 255);
    }
    FastLED.show();
    delay(delayTime);
    for(int j = 0; j < 10; j++){
      leds[i+j] = CRGB::Black;
    }
  }
 
}

// Shifts multiple pixel from the start of strip to the end. The color of each pixel is randomized.
// delayTime: indicates how long the pixels are shown on each LED
void showProgramShiftMultiPixel(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) { 
    for (int j = i; j > 0; --j) {
      leds[j] = leds[j-1];
    }
    CRGB newPixel = CHSV(random8(), 255, 255);
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
  }
}
// main program
void loop() {

  rainbow3(10);

}

