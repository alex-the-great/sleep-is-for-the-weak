const int line_sensor[2] = {A4, A3};
#define THRESHOLD 500

void setup() {
  //pinMode( line_sensor[0], INPUT );
  //pinMode( line_sensor[1], INPUT );
  Serial.begin( 9600 );
  
}

void loop() { 
  int line_sensor_1_val = analogRead( line_sensor[0] );
  int line_sensor_2_val = analogRead( line_sensor[1] );
  Serial.print( "1: " );
  Serial.println( line_sensor_1_val );
  
  Serial.print( "2: " );
  Serial.println( line_sensor_2_val );
  
  if ( line_sensor_1_val < THRESHOLD && line_sensor_2_val < THRESHOLD ) {
    Serial.println( "On white" );
  } else if ( line_sensor_1_val < THRESHOLD && line_sensor_2_val > THRESHOLD ) {
    Serial.println( "Line sensor 2 is off " );
  } else if ( line_sensor_1_val > THRESHOLD && line_sensor_2_val < THRESHOLD ) {
    Serial.println( "Line sensor 1 is off " );
  } else {
    Serial.println( "Intersection" );
  }
  delay( 300 );
}
