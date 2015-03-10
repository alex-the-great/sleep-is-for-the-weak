const int analogPin[2] = {A3, A4};
void setup ()
{
   Serial.begin( 9600 );
}
void loop ()
{
  int val[2];
  val[0] = analogRead( analogPin[0] );
  val[1] = analogRead( analogPin[1] );
  
  Serial.print( "A3: " );
  Serial.println( val[0] );
  
  Serial.print( "A4: " );
  Serial.println( val[1] );
  
  delay( 500 );
}
