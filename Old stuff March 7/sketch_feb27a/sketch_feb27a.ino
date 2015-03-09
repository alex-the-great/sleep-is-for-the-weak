//const int left_motor_pin[] = { 11, 10 };
const int right_motor_pin[] = { 6, 12 };
//const int ping_pin = ;
//const int leftLDR_pin = ;
//const int rightLDR_pin = ;

void setup() {
  Serial.begin( 9600 );
  
  //pinMode( left_motor_pin[0], OUTPUT );
//  Serial.print( left_motor_pin[0] );
  //pinMode( left_motor_pin[1], OUTPUT );
  
  pinMode( right_motor_pin[0], OUTPUT );
  pinMode( right_motor_pin[1], OUTPUT );
  pinMode( A1, OUTPUT );
  
  digital
  
  
  
  
  
  //delay( 2000 );
  
   
}

void loop () {
  /*
  analogWrite( right_motor_pin[0], 127 );
  analogWrite( left_motor_pin[0], 127 );
  
  analogWrite( right_motor_pin[1], 0 );
  analogWrite( left_motor_pin[1], 0 );
  
  analogWrite( right_motor_pin[0], 0 );
  analogWrite( left_motor_pin[0], 0 );  
  
  analogWrite( right_motor_pin[1], 0 );
  analogWrite( left_motor_pin[1], 0 );
  */
  Serial.println("one");
  digitalWrite( right_motor_pin[0], HIGH);
  digitalWrite( right_motor_pin[1], LOW);
  
  //digitalWrite( left_motor_pin[0], HIGH);
  //digitalWrite( left_motor_pin[1], LOW);
  
  delay(1000);
  //analogWrite( A1, 255 );
  Serial.println("two");
  digitalWrite( right_motor_pin[0], LOW);
  digitalWrite( right_motor_pin[1], HIGH);
  
  //digitalWrite( left_motor_pin[0], LOW);
  //digitalWrite( left_motor_pin[1], HIGH);
  delay(1000);
  
  //digitalWrite( left_motor_pin[1], LOW );
  digitalWrite( right_motor_pin[0], LOW );
  
  //digitalWrite( left_motor_pin[0], LOW );
  digitalWrite( right_motor_pin[1], LOW );
  
  delay( 1000 );
  Serial.print( "why stoppu" );
  /**analogWrite( left_motor_pin[0], 255 );
  analogWrite( right_motor_pin[0], 255 );
  
  
  analogWrite( left_motor_pin[1], 0 );
  analogWrite( right_motor_pin[1], 0 );
  
  delay( 2000 );
  analogWrite( left_motor_pin[0], 0 );
  analogWrite( right_motor_pin[0], 0 );
  delay(2000);**/
}
