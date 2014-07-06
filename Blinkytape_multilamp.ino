#include <FastLED.h>
#include <Button.h>
#define LED_COUNT 60
#define LED_OUT 13
#define BUTTON_IN 10

#define FLASHLIGHT 0
#define RED_BEACON 1
#define AREA_LIGHT_DIM 2
#define AREA_LIGHT_BRIGHT 3

struct CRGB leds[LED_COUNT];
int count = 0;
int dim = 0;
int mode = FLASHLIGHT;

Button button = Button(BUTTON_IN, BUTTON_PULLUP_INTERNAL, true, 50);

void onRelease(Button& b) {
  if (mode == AREA_LIGHT_BRIGHT) {
    mode = FLASHLIGHT;
  } 
  else {
    mode++;
  }
}

void setup()
{
  button.releaseHandler(onRelease);
  FastLED.addLeds<WS2812B, LED_OUT, GRB>(leds, LED_COUNT);
  LEDS.showColor(CRGB(0, 0, 0));
  LEDS.setBrightness(90); // Limit max current draw to 1A
  LEDS.show();
  Serial.begin(57600);
}

void red_beacon() {
  for(count = LED_COUNT - 1; count >= 0; count--){
    leds[count] = CRGB::Black;
  }    
  for(dim = 0; dim <= 85; dim++){
    for(count = LED_COUNT - 1; count >= 0; count--){
      leds[count] += CRGB(3,0,0);
    }
    FastLED.show();
    button.process();
    delay(30);
  }
  for(dim = 85; dim >= 0; dim--){
    for(count = LED_COUNT - 1; count >= 0; count--){
      leds[count] -= CRGB(3,0,0);
    }
    FastLED.show();
    button.process();
    delay(30);
  }
}

void flashlight () {
  for(count = LED_COUNT - 1; count >= 0; count--){
    leds[count] = CRGB::Black;
  }    
  for (count = 27; count <= 29; count ++) {
    leds[count] = CRGB::White;
  }
  FastLED.setBrightness(93);
  FastLED.show();
}

void area_light_bright () {
  for (count = LED_COUNT - 1; count >= 0; count --) {
    leds[count] = CRGB::White;
  }
  FastLED.setBrightness(90);
  FastLED.show();
}

void area_light_dim () {
  for (count = LED_COUNT - 1; count >= 0; count --) {
    leds[count] = CRGB::White;
  }
  FastLED.setBrightness(30);
  FastLED.show();
}

void loop() {
  switch(mode) {
  case FLASHLIGHT:
    flashlight();
    break;
  case RED_BEACON:
    red_beacon();
    break;
  case AREA_LIGHT_DIM:
    area_light_dim();
    break;
  case AREA_LIGHT_BRIGHT:
    area_light_bright();
    break;
  }
  button.process();
  Serial.println(mode);
}






