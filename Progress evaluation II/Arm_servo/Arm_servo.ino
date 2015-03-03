// Nimbus 2000 (Cleansweep)

/*

  I solemnly swear I am up to no good

*/

#include <Servo.h>

Servo nimbus;
int magicAngle = 0;

void setup (){
  
  nimbus.attach( 9 );
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

