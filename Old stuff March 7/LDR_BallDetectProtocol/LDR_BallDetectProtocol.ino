/*

  I solemnly swear I am up to no good
  
  Code done in collaboration by Saima Ali and Alex Gulka
  MAKE SURE TO KEEP BOTTOM PHOTORESITOR CLEAR BEFORE LED SIGNAL LIGHTS UP
  
  AER201, Winter of 2015
  EngSci 1T7

*/

// MAKE SURE TO KEEP BOTTOM PHOTORESITOR CLEAR BEFORE LED SIGNAL LIGHTS UP
// MAKE SURE TO KEEP BOTTOM PHOTORESITOR CLEAR BEFORE LED SIGNAL LIGHTS UP
// MAKE SURE TO KEEP BOTTOM PHOTORESITOR CLEAR BEFORE LED SIGNAL LIGHTS UP

const int photoresistor_bottom = A1;
const int photoresistor_top = A4;
const int fiatLux = 8;
const int multiplier =20;

int motor_pin_1 = 5;
int motor_pin_2 = 6;

int value = 0;
int value2 = 0;
int init_value = 0;
int init_value2 = 0;
int error_margin2;
int error_margin;

void setup()
{
  pinMode( fiatLux, OUTPUT );
  pinMode( motor_pin_1, OUTPUT );  
  pinMode( motor_pin_2, OUTPUT );
  
  //initialize communication with the serial monitor
  Serial.begin(9600); 
  
  //read an initial calibration value for the photoresistor
  
  init_value = analogRead( photoresistor_bottom ); 
  init_value2 = analogRead( photoresistor_top );
  /*
  delay( 10000 );
  
  int old_value = init_value;
  int old_value2 = init_value2;
  
  init_value = analogRead( photoresistor_bottom );
  init_value2 = analogRead(photoresistor_top);
  
  error_margin = ( old_value - init_value ); //getting an idea of the error, will probably need to modify at some point
  Serial.println(error_margin);
  error_margin = abs( error_margin );
  
  error_margin2 = ( old_value2 - init_value2 );
  error_margin2 = abs( error_margin2 );
  
  
  init_value = ( init_value + old_value )/2; //taking the average here  
  init_value2 = ( init_value2 + old_value2 )/2;
  // I just realized, might need 2 initialization values (ugh)

  /* Ready signal - LUMOS! LED lighting up means calibration is done, go ahead and do what you like*/
  // MAKE SURE TO KEEP BOTTOM PHOTORESITOR CLEAR BEFORE LED SIGNAL LIGHTS UP
  
  error_margin = 1;
  error_margin2 = 1;
  
  digitalWrite( fiatLux, HIGH );
  delay( 500 );
  digitalWrite( fiatLux, LOW );
}

void loop()
{
  value = analogRead(photoresistor_bottom); 
  value2 = analogRead(photoresistor_top);
  //read photoresistor voltage
  
  Serial.print("Init: ");
  Serial.println(init_value);
  Serial.print("Value: ");
  Serial.println(value);
  Serial.print("Init2: ");
  Serial.println(init_value2);
  Serial.print("Value2: ");
  Serial.println(value2);
  Serial.println(error_margin);
  Serial.println(error_margin2);
  
  if (value > (init_value + (error_margin * multiplier))) { // if a ball is detected at the lower photoresistor
    Serial.println( "Read greater value on bottom" );

    analogWrite(motor_pin_1, 255); //turn the motor to lift the ball
    analogWrite(motor_pin_2, 0); //same thing, just turning the motor
        
    value2 = analogRead( photoresistor_top ); // read the top photoresistor voltage
    while( value2 < (init_value2 + (error_margin2 * multiplier)) ) // until the ledge reaches the top, keep the motor running
    {
      delay(20);
      value2 = analogRead(photoresistor_top); //keep running
      
      Serial.print("Value2: ");
      Serial.println(value2);
    }
    
    analogWrite(motor_pin_1, 0 ); // top photoresistor is reached, stop the motor
    delay( 1000 ); // wait for 2 seconds
    
    Serial.println("BEFORE MOTOR REVERSES");

    analogWrite( motor_pin_2, 255 ); // reverse motor direction
    
    Serial.println( "Reading bottom photoresistor" );
    value = analogRead( photoresistor_bottom ); 
    while ( value < (init_value + (error_margin * multiplier) ) ) // check to make sure the bottom photoresistor has not been reached
    {
      delay(20);
      value = analogRead(photoresistor_bottom);
    }

   
    analogWrite( motor_pin_2, 0 ); // as soon as the base reaches the bottom, stop the motor
    
    Serial.println( "Finished loop, dinosaur" );
   
    //digitalWrite(fiatLux, HIGH);
    

  }/*end if*/
  
} //end loop


/*

  Mischief managed
  
*/

