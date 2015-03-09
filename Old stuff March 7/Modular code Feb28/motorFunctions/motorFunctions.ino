/*

  I solemnly swear I am up to no good
  Saima Ali
  EngSci 1T7
  
*/


// Motor control functions

void driveForward( int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[0], PWM_val );
  analogWrite( motorPin_array[1], 0 );
}

void driveBackward( int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[0], 0 );
  analogWrite( motorPin_array[1], PWM_val );
}

void driveStop( int motorPin_array[] ) {
  analogWrite( motorPin_array[0], 0 );
  analogWrite( motorPin_array[1], 0 );
}

void turn( int motorPin_1_array, int motorPin_2_array, byte PWM_val, int dir ) {
  //dir is 0 for motor1 cw, motor 2 ccw
  //dir is 1 for motor1 ccw, motor2 cw
  if( !dir ) {
    driveForward( motorPin_1_array, PWM_val );
    driveBackward( motorPin_2_array, PWM_val );
  } else { 
    driveBackward( motorPin_1_array, PWM_val );
    driveForward( motorPin_2_array, PWM_val );
  }
  
}

/*

  Mischief managed

*/
