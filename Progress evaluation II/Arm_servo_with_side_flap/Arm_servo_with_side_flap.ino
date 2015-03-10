// Nimbus 2000 (Cleansweep)

/*

  I solemnly swear I am up to no good

*/

#include <Servo.h>

Servo nimbus;
Servo tail;

void setup (){
  
  nimbus.attach( 9 );
  tail.attach( A2 );
  nimbus.write( 168 );
  
  tail.write( 100 );
  delay( 2000 );
  tail.write( 110 );
  delay( 300 );
  /*tail.write( );
  delay( 10 );*/
  
  //125 is down on the ground
  //70-80 is inclined upwards
  

  //delay( 300 );
  //nimbus.write( 75 );
  //delay( 300 );
  //nimbus.write( 168 );

}

void loop (){

}

/*

Mischief managed

*/

