/*****************************************************************************
         Copyright  EL KANTRI Youssef  All Rights Reserved
*****************************************************************************/

/*****************************************************************************
     Header Files included
 *****************************************************************************/

#include <Servo.h>

/******************************************************************************
   PROJECT : automatic soap pomp implementation
 ******************************************************************************
 *                                                                            *
    Written by  : EL KANTRI Youssef                       Date : 12/04/2020
 *                                                                            *
    Email : ysfelkantri1998@gmail.com
 ******************************************************************************
   MODIFICATION LOG:
 ******************************************************************************
   Modified by :                                           Date :
   Comments :
 ******************************************************************************/


///////////////////////parameters///////////////////////
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
long distance_in_cm = 100, val=0;
Servo myservo;

////////////////////////setup//////////////////////////
void setup(){
  Serial.begin(9600); // Starting Serial Communication
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input
}

void loop() {
long duration;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH); // using pulsein function to determine total time
  distance_in_cm = microsecondsToCentimeters(duration); // calling method
  if (distance_in_cm <= 10 ) { //if the user puts his hand below the 10 cm the servo will turn and the soap will be dropped out
    Serial.print("distance : ");
    Serial.print(distance_in_cm);
    Serial.println("cm");
    onServo();
  }
  delay(100);
}

long microsecondsToCentimeters(long microseconds) { // method to covert microsec to centimeters
  return microseconds / 29 / 2;
}

void onServo(){
  val = map(val, 0, 180, -90, 90);   // scale it to use it with the servo (value between 0 and 180)
  val=90;
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(500);
  val=0;
  myservo.write(val); 
  delay(500);
  Serial.println("approach your hand to ultrasonic sensor : (below 10cm) ");
}
