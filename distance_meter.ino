/*
   This code writen by "Ahmed Fadel" at 29/6/2016
   you can follow "Ahmed Fadel on Facebook from here
   www.fb.com/medofadel48
   This project is about measuring distance and display the ruslts
   on LCD
   Circuit and wiring methoed
   "Ultrasonnic"
   Trigpin to arduino pin 7
   echo pin to arduino pin 8
   "LCD"
   D4 >> pin 5
   D5 >> pin 4
   D6 >> pin 3
   D7 >> pin 2'
   R/W >> GND
   Enable >> pin 11
   RS >> pin 12
   V0 >> 10K pot
*/
#include <LiquidCrystal.h> // add LCD library 
#define echoPin 8
#define trigPin 7
int maximumRange = 100;
long duration , distance ;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Good day ^_^ "); //LCD start quouts 
}
void loop() {
  delay(1500);
  //ultrasinic initalize
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  //measure time 
  distance = duration / 58.2;  //calculate distance 
  if (distance >= maximumRange) {
    //what display on LCD 
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("distance is");
    lcd.setCursor(3, 2);
    lcd.print(distance);
    lcd.print (" cm far");
  }

  else {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("distance is");
    lcd.setCursor(3, 2);
    lcd.print(distance);
    lcd.print (" cm close");
  }

  delay(100);
}
