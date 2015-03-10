/*

  I solemnly swear I am up to no good
  Saima Ali
  EngSci 1T7

*/

const int threshold = 810;

const int left_motor_pin[] = { 11, 10 };
const int right_motor_pin[] = { 5, 6 };
//const int ping_pin = ;

const int leftLDR_pin = A2;
const int rightLDR_pin = A1;

int leftLDRval = 0;
int rightLDRval = 0;

int x = 0;
int y = 0;
int my_position[2] = { x, y };


void setup() {
  Serial.begin( 9600 );
  
  //pinModes
  pinMode( left_motor_pin[0], OUTPUT );
  pinMode( left_motor_pin[1], OUTPUT );
  pinMode( right_motor_pin[0], OUTPUT );
  pinMode( right_motor_pin[1], OUTPUT );
  
  pinMode( leftLDR_pin, INPUT );
  pinMode( rightLDR_pin, INPUT );
  
  //motor testing
  
  /*analogWrite( right_motor_pin[0], 127 );
  analogWrite( left_motor_pin[0], 127 );
  
  analogWrite( right_motor_pin[1], 0 );
  analogWrite( left_motor_pin[1], 0 );
  
  delay( 2000 );
  
  analogWrite( right_motor_pin[0], 0 );
  analogWrite( left_motor_pin[0], 0 );  
  
  analogWrite( right_motor_pin[1], 0 );
  analogWrite( left_motor_pin[1], 0 ); */ 
}

void loop () {
        Serial.println( "New Loop" );
	leftLDRval = analogRead( leftLDR_pin );
        Serial.print( "LEFT: " );
	Serial.println( leftLDRval );
	
	rightLDRval = analogRead( rightLDR_pin );
        Serial.print( "RIGHT: " );
	Serial.println( rightLDRval );

	
	if ( leftLDRval < threshold && rightLDRval < threshold )
	{
                Serial.println( "Move onwards" );
		analogWrite( right_motor_pin[0], 127 );
		analogWrite( right_motor_pin[1], 0 );

		analogWrite( left_motor_pin[0], 127 );
		analogWrite( left_motor_pin[1], 0 );
	} else if( leftLDRval > threshold && rightLDRval > threshold ) // intersection detected
	{
                Serial.println( "Dino dino coordinate" );
		Serial.print( "Y: " );
		Serial.println( y );
		y += 1;
		while(leftLDRval > threshold || rightLDRval > threshold)
                {
                   leftLDRval = analogRead( leftLDR_pin );
                   rightLDRval = analogRead( rightLDR_pin );
                 
		    analogWrite( right_motor_pin[0], 127 );
		    analogWrite( right_motor_pin[1], 0 );

		    analogWrite( left_motor_pin[0], 127 );
		    analogWrite( left_motor_pin[1], 0 );
                 }

	} 
	else if ( leftLDRval < threshold && rightLDRval > threshold )
	{
                //right on black
                Serial.println( "make left move" );
                
		analogWrite( left_motor_pin[0], 127 );
		analogWrite( left_motor_pin[1], 0 );

		analogWrite( right_motor_pin[0], 0 );
		analogWrite( right_motor_pin[1], 0 );
	}
	else if ( leftLDRval > threshold && rightLDRval < threshold ){
                Serial.println( "make right move" );
                
		analogWrite( right_motor_pin[0], 127 );
		analogWrite( right_motor_pin[1], 0 );

		analogWrite( left_motor_pin[0], 0 );
		analogWrite( left_motor_pin[1], 0 );
	} else {
                Serial.println( "Travel onwards" );
                
		analogWrite( right_motor_pin[0], 127 );
		analogWrite( right_motor_pin[1], 0 );

		analogWrite( left_motor_pin[0], 127 );
		analogWrite( left_motor_pin[1], 0 );
        }


    
    //delay( 300 );
  
}

/*

  Mischief managed

*/
