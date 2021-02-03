// joystick variables
int VRx = A2;
int VRy = A3;

int xPosition = 0;
int yPosition = 0;

int mapX = 0;
int mapY = 0;

// buzzer variables
const int buzzer = 1;

// timer variables
unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {


  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(buzzer, OUTPUT); t

}

void loop() {
  joyStick();
  whine();
  purr();
  growl();


}

void joyStick() { //function that maps the joystick values
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);

  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
}
void purr() { // function that makes a happy sound when the stick is moves the correct way
  if (mapX < -50 && mapY > -75 && mapY < 75) {

    tone(buzzer, 1000); // Send 1KHz sound signal for happy sounds
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
  }
}

void growl() { // function that makes a growling sound when stick moved the wrong way
  if (mapX > 50 || mapY < -75 || mapY > 75) {
    tone(buzzer, 50); // Send 50Hz sound signal for gowl
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
  }
}
void whine() { // makes a whinig sound every so often 
  unsigned long currentMillis = millis(); // timer declaration
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    tone(buzzer, 1100);
    delay(200);
    noTone(buzzer);
    delay(200);
    tone(buzzer, 1100);
    delay(200);
    noTone(buzzer);


  }
}
