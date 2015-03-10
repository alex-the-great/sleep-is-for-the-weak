// Nimbus 2000 (Cleansweep)

/*

  I solemnly swear I am up to no good

*/

#include <Servo.h>

//int felix = A0;
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
  /*for ( magicAngle = -91; magicAngle < -31; magicAngle += 1 ){
    nimbus.write( magicAngle );
    delay( 15 );
  }
  for ( magicAngle = -91; magicAngle >= -171; magicAngle -= 1 ){
    nimbus.write( magicAngle );
    delay( 15 );
  }*/
  //nimbus.write(0);
}

void loop (){

}

/*

Mischief managed

*/

