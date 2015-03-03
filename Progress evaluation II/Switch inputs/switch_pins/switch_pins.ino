const int switchPins[4] = {13,12,8,7};
const int LEDPin = 4;
int obstacle_1[][2] = {{0,0}, {0,0}, {0,0}};
int obstacle_2[][2] = {{0,0}, {0,0}, {0,0}};
int key_readings[3];
int counter = 0;
//int obstacle[2] = { obstacle_1, obstacle_2 };

void setup (){
  pinMode( switchPins[0], INPUT );
  pinMode( switchPins[1], INPUT );
  pinMode( switchPins[2], INPUT );
  pinMode( switchPins[3], INPUT );
  
  pinMode( LEDPin, OUTPUT );
  Serial.begin( 9600 );
}  
  
void loop (){
  int key_pressed = readKeys();
  if( key_pressed ){
    digitalWrite( LEDPin, HIGH );
  }
  delay( 1000 );
  digitalWrite( LEDPin, LOW );
  
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
