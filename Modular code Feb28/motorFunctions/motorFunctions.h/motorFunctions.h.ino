/*

  I solemnly swear I am up to no good
  Saima Ali
  EngSci 1T7
  
  Motor control functions
  
*/
#ifndef motorFunctions_h
#define motorFunctions_h

#include "Arduino.h" 

void driveForward( int motorPin_array[], byte PWM_val );
void driveBackward( int motorPin_array[], byte PWM_val );
void driveStop( int motorPin_array[] );

#endif
