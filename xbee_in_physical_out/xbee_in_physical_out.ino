/*
  
  (Serial) XBee IN » Physical OUT
  
  Wireless multi-node machine inspired by "Rube Goldberg Machine" 
  Project for ITP Class Understanding Networks by Tom Igoe

  Arduino waiting for a specific serial message input.
  
  Then, a toy car swithed motor is triggered to start motion.
  Digital out form the Arduino is connected to the base of a NPN transistor
  through a 220Ω resistor. Emitter connected to ground, and Collector to one of the toys switch leads. The
  other lead from the toy, to ground. 
  
  Code on https://github.com/sergiomajluf/Goldberg-machine
  Game Instructions on http://itp.nyu.edu/physcomp/Labs/XBeeTelephoneGame
  
  Sergio Majluf and Donna Miller
  Understanding Networks, by Tom Igoe
  November 2013

*/


int myGroupNumber = 6;
int toyTrigger = 8;
int testLED = 13;

void setup() {
  // initialize serial communiation:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo & Micro
  }
  pinMode(testLED, OUTPUT);
  pinMode(toyTrigger, OUTPUT);
}

void loop() {
  int serialValue = 0;
  // listen for Serial input. This line
  // expects an ASCII-encoded numeric string:
  if (Serial.available() > 0) {
    digitalWrite(testLED, HIGH);
    
    serialValue = Serial.parseInt();
    //Serial.print("received ");
    //Serial.println(serialValue);
    digitalWrite(testLED, LOW);
  }

  // check to see if serial value is my group number:
  if (serialValue == myGroupNumber ) {
    // message was my group number
    // so generate physical output:
    //Serial.println("SUCCESS");
    digitalWrite(testLED, HIGH);
    digitalWrite(toyTrigger, HIGH);  
    Serial.println(myGroupNumber+1);
    delay(2000);
    digitalWrite(testLED, LOW);
    digitalWrite(toyTrigger, LOW);  
  }  
  else {
    // stop physical outut:
    digitalWrite(testLED, LOW); 
  }
}
