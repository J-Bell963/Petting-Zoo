//Constants
const int pResistor = A1; // Photoresistor pin
const int ledPin=1;       // Led pin 

//Variables
int lightVal = 0;  // Store value from photoresistor 

int mapLight = 0;

// timer variables
unsigned long previousMillis = 0;
const long interval = 10000;

void setup(){
 
 pinMode(ledPin, OUTPUT);  // Set lepPin 
 pinMode(pResistor, INPUT);// Set pResistor 
}

void loop(){
  lightVal = analogRead(pResistor); 

  squinting();
blinking();
 
}

void squinting(){ //function that makes the light dim when the photoresistor value goes up

    mapLight = map(lightVal, 0, 1023, 255, 0);
analogWrite(ledPin, mapLight);
}

void blinking(){ //function that makes the cyclops blink every so often
  
    unsigned long currentMillis = millis(); // timer declaration 
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      
     analogWrite(ledPin, LOW);
     delay(75);
     analogWrite(ledPin, mapLight);
    }
  
}
