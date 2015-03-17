const int microSwitch_pin[2] = {12, 2}; //right left

const int motorPin_1_array[3] = { 7, 6, 3};
const int motorPin_2_array[3] = {10, 11, 9}; //left

const int line_sensor[2] = {A3, A2}; //right left

void setup()
{
  Serial.begin( 9600 );
  
  pinMode( microSwitch_pin[0], INPUT );
  pinMode( microSwitch_pin[1], INPUT );
  
  pinMode( motorPin_1_array[0], OUTPUT );
  pinMode( motorPin_1_array[1], OUTPUT );
  //pinMode( motorPin_1_array[2], OUTPUT );
  
  pinMode( motorPin_2_array[0], OUTPUT );
  pinMode( motorPin_2_array[1], OUTPUT );
  //pinMode( motorPin_2_array[2], OUTPUT );
  
  driveForward( motorPin_1_array, 127 );
  driveForward( motorPin_2_array, 127 );
  
  int rightSwitch_val = digitalRead( microSwitch_pin[0] );
  int leftSwitch_val = digitalRead( microSwitch_pin[1] );
  
  Serial.println( rightSwitch_val );
  Serial.println( leftSwitch_val );
  
  while( !leftSwitch_val ) {
    leftSwitch_val = digitalRead( microSwitch_pin[0] );
    Serial.println( rightSwitch_val );
  }
  driveStop( motorPin_2_array );
  
  while( !rightSwitch_val ) {
    rightSwitch_val = digitalRead( microSwitch_pin[1] );
    Serial.print( leftSwitch_val );
  }
  driveStop( motorPin_1_array );
  
  
}

void loop ()
{
}

void driveForward( const int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[2], PWM_val );
  digitalWrite( motorPin_array[0], 1 );
  digitalWrite( motorPin_array[1], 0 );
}

void driveBackward( const int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[2], PWM_val );
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 1 );
}

void driveStop( const int motorPin_array[] ) {
  //analogWrite( motorPin_array[2], 0 );
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 0 );
}
