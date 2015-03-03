const int switchPins[4] = {A1,12,8,7};
const int LEDPin = A2;
int obstacle[][2] = {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}};
int key_readings[3];
int reading_index = 0;
int counter = 0;
//int obstacle[2] = { obstacle_1, obstacle_2 };

void setup (){
  pinMode( switchPins[0], INPUT );
  pinMode( switchPins[1], INPUT );
  pinMode( switchPins[2], INPUT );
  pinMode( switchPins[3], INPUT );
  
  pinMode( LEDPin, OUTPUT );
  digitalWrite( LEDPin, LOW );
  Serial.begin( 9600 );
}  
  
void loop (){
  int key_pressed = readKeys();
  if( key_pressed ){
    digitalWrite( LEDPin, HIGH );
    Serial.println( "LED ON DRUGES" );
    delay( 1000 );
    digitalWrite( LEDPin, LOW );
    Serial.println( "LED IS OK NOW" );
    
    counter ++;
    Serial.print( "Counter: " );
    Serial.println( counter );
  }
  if( counter == 3 ) {
    counter = 0;
    obstacle[reading_index][0] = key_readings[0] + key_readings[1];
    Serial.print( "X: " );
    Serial.println( obstacle[reading_index][0] );
    obstacle[reading_index][1] = key_readings[2];
    
    Serial.print( "Y: " );
    Serial.println( obstacle[reading_index][1] );
    reading_index ++;
    Serial.print( "Reading index" );
    Serial.println( reading_index );
    if( reading_index == 6 ){
      while( 1 ){
        Serial.print( "Readind index is 6" );
        delay(10);
      }
    }
  }
  
  
}

int readKeys() {
  int key_pressed = 0;
  int reading[] = {0, 0, 0, 0};
  
  //first coordinate
  while( !key_pressed ){
    for( int i = 0; i < 4; i += 1 ) {
      reading[i] = digitalRead( switchPins[i] );
      if( reading[i] != 0 ) {
        key_pressed = 1;
        //key_readings[counter] = reading[i];
        key_readings[counter] = i;
        Serial.println( i );

      }
    }
  }
  delay( 2000 );
  return key_pressed;
  
}
