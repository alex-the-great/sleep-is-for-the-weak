// Nimbus 2000 (Cleansweep)

/*

  I solemnly swear I am up to no good

*/

#include <Servo.h>

Servo nimbus;
Servo tail;

void setup (){
  
  nimbus.attach( 9 );
  tail.attach( 10 );
  
  tail.write( );
  delay( 300 );
  tail.write( );
  delay( 300 );
  tail.write( );
  delay( 10 );
  
  //168 is down on the ground
  //70-80 is inclined upwards
  
  nimbus.write( 168 );
  delay( 300 );
  nimbus.write( 75 );
  delay( 300 );
  nimbus.write( 168 );

}

void loop (){

}

/*

Mischief managed

*/

