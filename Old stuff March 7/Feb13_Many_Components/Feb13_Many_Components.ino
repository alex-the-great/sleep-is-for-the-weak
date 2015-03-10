/*

  I solemnly swear I am up to no good
  
  Saima Ali
  EngSci 1T7

*/

#include <Servo.h>

const int microSwitch_1 = 10;
const int microSwitch_2 = 11;

const int motorPin_1 = 6;
const int motorPin_2 = 5;

const int fiatLux = 8; // this should not be in this scope, bad memory management

const int LDR_1 = A3;
const int LDR_2 = A4;

const int nimbusPin = 9;
Servo nimbus;
int magicAngle = 0;

int LDRinit_1 = 0;
int LDRinit_2 = 0;

int increment = 20;


void setup () {
  Serial.begin( 9600 );
  
  pinMode( microSwitch_1, INPUT );
  pinMode( microSwitch_2, INPUT );
  
  pinMode( motorPin_1, OUTPUT );
  pinMode( motorPin_2, OUTPUT );  
  
  pinMode( fiatLux, OUTPUT );
  nimbus.attach( nimbusPin );
  
  LDRinit_1 = analogRead( LDR_1 );
  LDRinit_2 = analogRead( LDR_2 );
  
  digitalWrite( fiatLux, HIGH ); // calibration done, LED lights up


  delay( 700 );
  digitalWrite( fiatLux, LOW );

  
  // Detect hopper presence from 2 microswitches
  byte microSwitch_Go = microSwitch_State( microSwitch_1, microSwitch_2 );
  Serial.print( "Micr. rnd 1:" );
  Serial.println( microSwitch_Go );
  
  while ( !microSwitch_Go ) {
    microSwitch_Go = microSwitch_State( microSwitch_1, microSwitch_2 );
    Serial.print( "Micr. Loop: " );
    Serial.println( microSwitch_Go );
    delay( 10 );
  }
  
}

void loop () {

  // Now microswitch says Go
  // Actuate servo motor
  nimbus.write( magicAngle ); // only tilts for now
  delay( 1000 );
  nimbus.write( 0 );
  
  Serial.println( "Is the ball there?" );
  
  // Check if the ball is there with LDR_1
  int LDRvalue_1 = analogRead( LDR_1 ); 
  if( LDRvalue_1 < ( LDRinit_1 + increment )) {
	delay( 1000 ); // wait a second -- need to calculate approximate time for ball to fall through
	LDRvalue_1 = analogRead( LDR_1 );
  }
  
  //actuate DC motor if ball is there

  if( LDRvalue_1 > ( LDRinit_1 + increment ) ) {
     Serial.println( "Yes" );
    analogWrite(motorPin_1, 255); //turn the motor to lift the ball
    analogWrite(motorPin_2, 0); //same thing, just turning the motor
      
    int LDRvalue_2 = analogRead( LDR_2 );
      
    while( LDRvalue_2 < ( LDRinit_2 + increment ) ) { //top
      delay( 20 );
      LDRvalue_2 = analogRead( LDR_2 );
     }
	 
    //reached the top
    analogWrite( motorPin_1, 0 ); //stop
    delay( 3000 ); // 3s pause
    analogWrite( motorPin_2, 255 ); // reverse
	
    delay( 5000 );// 5s until it reaches the bottom? do we need a stepper?
	analogWrite( motorPin_2, 0 ); // stop
  
  /*} else { // haven't secured the ball
	nimbus.write( magicAngle ); //tilt again to try
  }*/
  
  //haven't secured the ball, try again

  } /*else { // haven't secured the ball
	nimbus.write( magicAngle ); //tilt again to try
        delay( 1000 );
        nimbus.write( 0 );
  }*/
  

}

byte microSwitch_State ( int pin_1, int pin_2 ) {
  byte pin_1_val = digitalRead( pin_1 );
  byte pin_2_val = digitalRead( pin_2 );
  return ( pin_1_val && pin_2_val ); // are both the microwitches pressed?
}



/*

  Mischief ( hopefully ) managed

*/
