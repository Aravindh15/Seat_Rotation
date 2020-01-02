/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
#define LS A0      // left sensor
#define RS A1     //right sensor
#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  lcd.begin(16, 2);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
   for (pos = 90; pos <= 90; pos += 1) {
    myservo.write(pos);
    
   }


  
 if(!digitalRead(LS) && digitalRead(RS))    // right
  {
    delay(1000);
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    lcd.begin(16, 2);
    lcd.print("RIGHT DOOR"); 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }}
   if(digitalRead(LS) && !digitalRead(RS))     //  Left
  {
    delay(1000);
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    lcd.begin(16, 2);
    lcd.print("LEFT DOOR"); 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }}
   lcd.display();
   delay(500);
}
