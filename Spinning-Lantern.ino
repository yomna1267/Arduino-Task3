#include <Servo.h>

   int pinLed = 13;
   int sensorValue = 0;
   Servo myservo;  // create servo object to control a servo
   int pos = 0;    // variable to store the servo position
   const int buttonPin = 2;     // the number of the switch pin
   int buttonState = 0;         // variable for reading the pushbutton status
void setup()
{
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pinLed, OUTPUT);
  pinMode(buttonPin, INPUT);
  
}
void loop() {
  // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
  // check if the switch is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) 
   {
    // turn LED on:
    digitalWrite(pinLed, HIGH);
    
    for (pos = 0; pos < 180; pos += 1) 
       { 
        // goes from 0 degrees to 180 degrees
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);
       }
    
    for (pos = 180; pos > 0; pos -= 1) 
      { 
        // goes from 180 degrees to 0 degrees
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15); 
      }
   }
   else
    // turn LED off and stop myservo:
    digitalWrite(pinLed, LOW);

}
