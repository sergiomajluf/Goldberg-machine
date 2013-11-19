/*
  
  Physical IN » (XBee) Serial OUT
  
  Wireless multi-node machine inspired by "Rube Goldberg Machine" 
  Project for ITP Class Understanding Networks by Tom Igo

  Toy trigger is connected to the base of a NPN transistor through a 220Ω resistor.
  Emitter connected to ground, and Collector to one of the toys switch leads. The
  other lead from the toy, to ground.
  
  Game Instructions on http://itp.nyu.edu/physcomp/Labs/XBeeTelephoneGame
  
  Sergio Majluf and Donna Miller
  Understanding Networks, by Tom Igoe
  November 2013

*/

const int buttonPin = 2;    // the number of the pushbutton pin
const int greenLED = 4;      // the number of the LED pin
const int redLED = 5;
int myGroupNumber = 6;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // set initial LED state
  digitalWrite(greenLED, ledState);
  digitalWrite(redLED, !ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      ledState = HIGH;  
      //Serial.println("The wall is OK");

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = LOW;
        //Serial.println("The wall was crashed");
        Serial.print(myGroupNumber+1);
      }
    }
  }
  
  digitalWrite(greenLED, ledState);
  digitalWrite(redLED, !ledState);
  lastButtonState = reading;
}
