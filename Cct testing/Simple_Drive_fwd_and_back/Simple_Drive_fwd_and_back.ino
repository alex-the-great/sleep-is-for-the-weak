/*

  I solemnly swear I am up to no good
  Saima Ali
  EngSci 1T7
  
*/

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define TURN_TIME 1000
#define BOARDHEIGHT 9
#define BOARDWIDTH 8

#define THRESHOLD 300
#define SERVO_ANGLE 20

const int motorPin_1_array[3] = {8,9,6}; //right motor
const int motorPin_2_array[3] = {10,11,9}; //left motor

//const int line_sensor[2] = {A2, A3};

void setup () {
  pinMode( motorPin_1_array[0], OUTPUT );
  pinMode( motorPin_1_array[1], OUTPUT );
  //pinMode( motorPin_1_array[2], OUTPUT );
  pinMode( motorPin_2_array[0], OUTPUT );
  pinMode( motorPin_2_array[1], OUTPUT );
  //pinMode( motorPin_2_array[2], OUTPUT );
  
  Serial.begin( 9600 );

}

void loop () {
  
  driveForward( motorPin_1_array );
  driveForward( motorPin_2_array );
  Serial.println( "stop1" );
 
  delay( 3000 );
  
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  Serial.println( "stop2" );
  
  delay( 1000 );
  
  driveBackward( motorPin_1_array );
  driveBackward( motorPin_2_array );
  Serial.println( "stop3" );
  
  delay( 3000 );
  
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  Serial.println( "stop4" );
  
  delay( 1000 );
  
}


void driveForward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 1 );
  digitalWrite( motorPin_array[1], 0 );
  analogWrite(motorPin_array[2],127);
}

void driveBackward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 1 );
  analogWrite(motorPin_array[2], 127);
}

void driveStop( const int motorPin_array[] ) {
  //analogWrite( motorPin_array[2], 0 );
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 0 );
}
