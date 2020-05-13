#include <Stepper.h>

const int stepsPerRevolution1 = 200;  // change this to fit the number of steps per revolution
const int stepsPerRevolution2 = 200;
// for your motor
int val;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution1, 4, 5, 6, 7);
Stepper myStepper2(stepsPerRevolution2, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {  
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'w') //if value input is equals to d
    {
    Serial.println("yclockwise");
  myStepper1.step(0.01*stepsPerRevolution1);
 
     }
    if (val == 's') //if value input is equals to a
    {
      Serial.println("ycounterclockwise");
  myStepper1.step(-0.01*stepsPerRevolution1);
   
    }
    if (val == 'd') //if value input is equals to w
    {
    Serial.println("xclockwise");
  myStepper2.step(0.01*stepsPerRevolution2);
 
     }
     if (val == 'a') //if value input is equals to s
    {
    Serial.println("xcounterclockwise");
  myStepper2.step(-0.01*stepsPerRevolution2);
 
     }
  }
  else {
  myStepper1.step(0);
  myStepper2.step(0);
  }
}
 //units and som e more(this was a test for github)

  
