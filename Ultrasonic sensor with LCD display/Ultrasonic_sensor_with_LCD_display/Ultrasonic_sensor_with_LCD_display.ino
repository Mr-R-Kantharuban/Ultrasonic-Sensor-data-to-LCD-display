#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);  //Create Liquid Crystal Object called LCD
 
int trigPin=9; //Sensor Trip pin connected to Arduino pin 9
int echoPin=7;  //Sensor Echo pin connected to Arduino pin 7
int myCounter=0;  //declare your variable myCounter and set to 0
int servoControlPin=6; //Servo control line is connected to pin 6
float pingTime;  //time for ping to travel from the sensor to the target and return
float targetDistance; //Distance to Target in Centimeters
float speedOfSound=776.5; //Speed of sound in miles per hour
 
void setup() {
  
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
LCD.begin(16,2); //Tell Arduino to start your 16x2 LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("Distance:");  //Print Message on First Row
}
 
void loop() {
  
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime=pingTime/3600; //convert pingtime to hours by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingTime;  //This will be in miles, since we declared the speed of sound as kilometers per hour; although we're going to convert it back to centimeters 
  targetDistance=targetDistance/2; //Remember ping travels to the target and back from the target, so you must divide by 2 for actual target distance.
  targetDistance= targetDistance*160934,4;    //Convert miles to centimeters by multipling by 160934,4 

 
  
  LCD.setCursor(0,1);  //Set the cursor to the first column of the second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to the first column of the second row
  LCD.print(targetDistance); //Print measured distance
  LCD.print(" centimeters");  //Print your units
  delay(250); //Pause to let things settle
  
}
