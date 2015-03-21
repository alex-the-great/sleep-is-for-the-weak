//
/*

  I solemnly swear I am up to no good
  Saima Ali
  EngSci 1T7
  
*/

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define TURN_TIME 1000
#define BOARDHEIGHT 9
#define BOARDWIDTH 8

#define THRESHOLD 200
#define SERVO_ANGLE 20

#define PWM_INCREMENT 70
#define LINE_TIME 200

// int motor_1_state[3];
// int motor_2_state[3];

//right motor
//digital, digital, pwm
const int motorPin_1_array[3] = { 7, 6, 3 };
//left motor
//digital, digital, pwm
const int motorPin_2_array[3] = { 10, 11, 9 };
//right, left
const int line_sensor[3] = { A2, A3, A4 }; //the third is the center one

//left A2, 10 11 9



int myPos[2] = { 0, 0 }; // scope of the variable - entire file
byte face = LEFT; //direction currently facing 
byte dir = LEFT; //direction travelling/to travel in

void setup () {
  pinMode( motorPin_1_array[0], OUTPUT );
  pinMode( motorPin_1_array[1], OUTPUT );
  //pinMode( motorPin_1_array[2], OUTPUT );
  
  pinMode( motorPin_2_array[0], OUTPUT );
  pinMode( motorPin_2_array[1], OUTPUT );
  //pinMode( motorPin_2_array[2], OUTPUT );
  
  //pinMode( line_sensor[0], INPUT );
  //pinMode( line_sensor[1], INPUT );

  Serial.begin( 9600 );
  
}

void loop () {
  lineFollow(80);

}

// Coordinates

void logCoordinate() {
  if( dir == LEFT ) {
    myPos[0] += 1;
  } else if ( dir == RIGHT ) {
    myPos[0] -= 1;
  } else if ( dir == UP ) {
    myPos[1] += 1;
  } else if (dir == DOWN ) {
    myPos[1] -= 1;
  }
}

/*int findTurnDir() {
  int turn_dir;
  if ( ( dir == face ) || ( abs( dir - face ) == 2 ) ) {
    turn_dir = 2; // donut turn
  } else if ( ( abs( dir - face ) == 1 )) {
    turn_dir = 0; //turn cw
  } else {
    turn_dir = 1; //turn ccw
  }
  return turn_dir;
}*/

/*void linearMove() {
  int turnDir = findTurnDir();
  turn( turnDir );
  driveForward( motorPin_1_array );
  driveForward( motorPin_2_array );
}*/

void checkIntersection( int LDR1_val, int LDR2_val ) {
  if( LDR1_val > THRESHOLD && LDR2_val > THRESHOLD ) {
    Serial.println( "Intersection" );
    logCoordinate();
    while( LDR1_val > THRESHOLD && LDR2_val > THRESHOLD ) {
      Serial.println( "Stuck in the loop" );
      continue;
    }
    Serial.println( "Coordinate logged" );
  } 
}

int AmIThereYet( int target ) {
  int index = ( ( dir == UP ) || ( dir == DOWN ) ); 
  return ( myPos[index] == target );
}

void lineFollow( byte PWM_val ) {
  
  int line_1_val = analogRead( line_sensor[0] );
  int line_2_val = analogRead( line_sensor[1] );
  int line_3_val = analogRead( line_sensor[2] );
  
  driveForward( motorPin_1_array, PWM_val + PWM_INCREMENT );
  driveForward( motorPin_2_array, PWM_val );
  
  while ( line_2_val < THRESHOLD ) {
    line_2_val = analogRead( line_sensor[1] );
    continue;
    
  } 
  //start to the right, wait till left sensor is hit
  // left sensor is hit
  
  Serial.println( "Left on black" );
  
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  
  delay( 1000 );
  
  driveStop( motorPin_1_array );
  driveForward( motorPin_2_array, PWM_val );
  
  //pivot
  line_3_val = analogRead( line_sensor[2] );
  Serial.println( "Reading 3" );
  
  while( line_3_val < THRESHOLD ) {
    line_3_val = analogRead( line_sensor[2] );
  }
  
  Serial.println( line_3_val );
  
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  
  delay( 1000 );
  
  line_2_val = analogRead( line_sensor[1] );
  
  Serial.println( line_2_val );
  
  driveForward( motorPin_2_array, PWM_val + PWM_INCREMENT);
  driveForward( motorPin_1_array,  PWM_val );
  
  while( line_2_val < THRESHOLD ) {
    line_2_val = analogRead( line_sensor[1] );
    Serial.println( "NOT" );
    delay( 30 );  
}
  // waiting to see if it gets back on the line
  //now, wait for it to overshoot

  /*while( line_2_val >= THRESHOLD ) {
    line_2_val = analogRead( line_sensor[1] );
    Serial.println( "LINE" );
    delay( 30 );
  }*/
  
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  delay( 1000 );
  
  //pivot
  
  driveForward( motorPin_1_array, PWM_val );
  driveStop( motorPin_2_array );
  
  line_3_val = analogRead( line_sensor[2] );
  while( line_3_val < THRESHOLD ){
    delay( 10 );
    line_3_val = analogRead( line_sensor[2] );
  }
  
  driveStop( motorPin_1_array );
  
  delay( 10000 );
  
}

/**void lineFollow(byte PWM_val) {
  int time_to_black_1 = 0;
  int time_to_black_2 = 0;
  
  int line_1_val = analogRead( line_sensor[0] );
  int line_2_val = analogRead( line_sensor[1] );

  Serial.print( "1: " );
  Serial.println( line_1_val );
  
  Serial.print( "2: " );
  Serial.println( line_2_val );
  //checkIntersection( line_sensor[0], line_sensor[1] );
  
  if ( line_1_val > THRESHOLD && line_2_val > THRESHOLD ) {
    Serial.println( "intersection" );
    
    driveForward( motorPin_1_array, PWM_val );
    driveForward( motorPin_2_array, PWM_val );
    
    //while( line_1_val > THRESHOLD && line_2_val > THRESHOLD ) {
    //  delay( 20 );
    //}
    
  } else if ( line_1_val < THRESHOLD && line_2_val < THRESHOLD ) {
    
    Serial.println( "On white" );
    
    driveForward( motorPin_1_array, PWM_val );
    driveForward( motorPin_2_array, PWM_val );
  
  } else if ( line_1_val < THRESHOLD && line_2_val > THRESHOLD ) {
    
    Serial.println( "Line sensor 2 is off " );
    time_to_black_2 = millis();
    
    //if( abs( time_to_black_2 - time_to_black_1 ) > LINE_TIME ) {
      driveForward( motorPin_1_array, PWM_val + PWM);
      driveForward( motorPin_2_array, PWM_val );

  } else if ( line_1_val > THRESHOLD && line_2_val < THRESHOLD ) {
    Serial.println( "Line sensor 1 is off " );
    
    time_to_black_1 = millis();
    
    //if( abs( time_to_black_2 - time_to_black_1 ) > LINE_TIME ) {
      driveForward( motorPin_2_array, PWM_val + PWM_INCREMENT );
      driveForward( motorPin_1_array, PWM_val );
      
    }
      
}**/

/*
void getToWall() {
  int targetWallPos;
  if( myPos[0] <= 0 ) {
    dir = LEFT;
    targetWallPos = -4;
  } else {
    dir = RIGHT;
    targetWallPos = 4;
  }
  
  linearMove();
  int arrival = AmIThereYet( targetWallPos );
  int oldPos = myPos[0];
  while ( !arrival ) {
    lineFollow();
    while( myPos[0] == oldPos ){
      lineFollow();
    }
    oldPos = myPos[0];
    arrival = AmIThereYet( targetWallPos );
  }
  //I am there!
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
}*/

// Motor control functions

void driveSpeed( const int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[2], PWM_val );
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

void changeFace( int dir ){
/*here dir = +/- 1, this function changes the global value of "face" after it makes a turn*/
  face = face + dir;
  if ( face < 0 )
  {
    face = 3;
  } else if ( face > 3 ) {
    face = 0;  
  }
}

void turn( int turn_dir, byte PWM_val ) {
  //dir is 0 for motor1 cw, motor 2 ccw
  //dir is 1 for motor1 ccw, motor2 cw
  if( !turn_dir ) {
    driveForward( motorPin_1_array, PWM_val );
    driveBackward( motorPin_2_array, PWM_val );
    changeFace(1);
  } else if (turn_dir == 2) {
    return;
  } else { 
    driveBackward( motorPin_1_array, PWM_val );
    driveForward( motorPin_2_array, PWM_val );
    changeFace(-1);
  } 
  
  delay( TURN_TIME );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  
}


/*

  Mischief managed

*/
