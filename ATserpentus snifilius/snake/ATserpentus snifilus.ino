#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 1 megohm resistor between pins 4 & 2, pin 2 is sensor pin

#define LED_PIN    1

#define LED_COUNT 5
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup(){

cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
Serial.begin(9600);

strip.begin();           
  strip.show();            
  strip.setBrightness(50); 
}

void loop(){


tongeFlick();



}

void colorWipe(uint32_t color, int wait) { //function to make the lights look like a tounge flicking out
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                         
    delay(wait);                           
  }
}

void colorHide(uint32_t color, int wait) { // function to make the lights look like a tounge flicking in
  for(int i=4; i<strip.numPixels(); i--) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
    delay(wait);                           
  }
}


void tongeFlick(){ // function that reads the touch sensor then runs the lights
  long total1 = cs_4_2.capacitiveSensor(30);
if (total1 > 50){
  colorWipe(strip.Color(255,0,0), 50); // Red
}else{
 colorHide(strip.Color(0,0,0), 50); // off
}
}
