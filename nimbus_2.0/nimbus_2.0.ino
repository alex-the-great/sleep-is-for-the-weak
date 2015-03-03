// Nimbus 2000 (Cleansweep)

/*

  I solemnly swear I am up to no good

*/

#include <Servo.h>

int felix = A2;
Servo nimbus;
int magicAngle = 0;

void setup (){
  nimbus.attach( 9 );
  Serial.begin( 9600 );
}

void loop (){
  magicAngle = analogRead( felix );
  Serial.println( magicAngle );
  
  magicAngle = map( magicAngle, 0, 1023, 0, 179 );
  Serial.println( magicAngle );
  
  nimbus.write( magicAngle );
  delay( 15 );
/*  for ( magicAngle = 0; magicAngle < 180; magicAngle += 1 ){
    nimbus.write( magicAngle );
    delay( 15 );
  }
  for ( magicAngle = 180; magicAngle >= 1; magicAngle -= 1 ){
    nimbus.write( magicAngle );
    delay( 15 );
  }
*/
}

/*

Mischief managed

*/

