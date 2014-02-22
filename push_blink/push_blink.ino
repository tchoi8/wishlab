/*
  Button Blink
 
 Blink light emitting diode(LED) connected to digital  
 pin 9, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 9 to ground 
 * pushbutton attached to pin 2 from Ground
 
 
------
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 This example code is in the public domain.
--------

 modified by KOBAKANT for the WishLab workshop
 http://www.kobakant.at/DIY/?p=4967
 
*/


 
int buttonPin = 2;    
int ledPin =  9;     

 
int buttonState = 0;        

void setup() {
    pinMode(ledPin, OUTPUT);      
    pinMode(buttonPin, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
 
  if (buttonState == LOW) {     
 
    digitalWrite(ledPin, HIGH);  
    delay(1000);
    digitalWrite(ledPin, LOW); 
    delay(1000);
  } 
  else {
     
    digitalWrite(ledPin, LOW); 
  }
}
