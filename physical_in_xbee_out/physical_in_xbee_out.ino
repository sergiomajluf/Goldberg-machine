/*
  
  Physical IN » (XBee) Serial OUT
  
  Wireless multi-node machine inspired by "Rube Goldberg Machine" 
  Project for ITP Class Understanding Networks by Tom Igoe

  Physical object is waitin for a collision, that is triggered by a simple pushbutton.
  Following code is based off the de-bouncing code. Once triggered, it
  will send a serial (wireless through Xbee) message to the next node
  in the Rube Goldberg network.
  
  Code on https://github.com/sergiomajluf/Goldberg-machine
  Game Instructions on http://itp.nyu.edu/physcomp/Labs/XBeeTelephoneGame
  
  Sergio Majluf and Donna Miller
  Understanding Networks, by Tom Igoe
  November 2013

*/

const int buttonPin = 2;
const int greenLED = 4;     // LED's provide state feedback
const int redLED = 5;
int myGroupNumber = 6;

// Variables will change:
int ledState = HIGH;         // will use this to light either LED
int buttonState;             // the current input reading
int lastButtonState = LOW;   // the previous reading

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
