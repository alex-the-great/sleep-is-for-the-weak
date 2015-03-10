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

#define THRESHOLD 300
#define SERVO_ANGLE 20;

//       byte PWM_val = 127;

//const int enable_1 = A1;
//const int enable_2 = A2;
const int motorPin_1_array[2] = {6, 12};
//left motor 10 11
//left line sensor A4
//right motor 3 5 
//right line sensor A3
const int motorPin_2_array[2] = {5, 11};
const int line_sensor[2] = {};
//const int servoPin = ;

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
  
  pinMode( line_sensor[0], INPUT );
  pinMode( line_sensor[1], INPUT );

  Serial.begin( 9600 );
  /*
  driveForward( motorPin_1_array );
  driveForward( motorPin_2_array );
  delay( 3000 );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  delay( 200 );
  driveBackward( motorPin_1_array );
  driveBackward( motorPin_2_array );
  delay( 3000 );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  
  turn( 0 );
  delay( TURN_TIME );*/
  

}

void loop () {
  lineFollow();
  Serial.print( "x: " );
  Serial.println( myPos[0] );
  Serial.print( "y : " );
  Serial.println( myPos[1] );
  
  delay( 200 );
  /**int LDR1_val = analogRead( LDRPin_1 );
  int LDR2_val = analogRead( LDRPin_2 );
  
  Serial.print( "LDR 1: " );
  Serial.println( LDR1_val );
  Serial.print( "LDR 2: " );
  Serial.println( LDR2_val );
  
  delay( 30 );**/
  /*
  driveForward( motorPin_1_array );
  driveForward( motorPin_2_array );
  delay( 3000 );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  delay( 200 );
  driveBackward( motorPin_1_array );
  driveBackward( motorPin_2_array );
  delay( 3000 );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  */
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


/**int *getPath( int target[2] ) {
  int *path[2];
  path[0] = target[0] - myPos[0];
  path[1] = target[1] - myPos[1];
  return path;
}**/

int findTurnDir() {
  int turn_dir;
  if ( ( dir == face ) || ( abs( dir - face ) == 2 ) ) {
    turn_dir = 2; // donut turn
  } else if ( ( abs( dir - face ) == 1 )) {
    turn_dir = 0; //turn cw
  } else {
    turn_dir = 1; //turn ccw
  }
  return turn_dir;
}

void linearMove() {
  int turnDir = findTurnDir();
  turn( turnDir );
  driveForward( motorPin_1_array );
  driveForward( motorPin_2_array );
}

void checkIntersection( int LDR1_val, int LDR2_val ) {
  if( LDR1_val > THRESHOLD && LDR2_val > THRESHOLD ) {
    logCoordinate();
    while( LDR1_val > THRESHOLD && LDR2_val > THRESHOLD ) {
      continue;
    }
  } 
}

int AmIThereYet( int target ) {
  int index = ( ( dir == UP ) || ( dir == DOWN ) ); 
  return ( myPos[index] == target );
}

void lineFollow() {
  int line_1_val = analogRead( line_sensor[0] );
  int line_2_val = analogRead( line_sensor[1] );
  //int line_sensor_1_val = analogRead( line_sensor[0] );
  //int line_sensor_2_val = analogRead( line_sensor[1] );
  Serial.print( "1: " );
  Serial.println( line_1_val );
  
  Serial.print( "2: " );
  Serial.println( line_2_val );
  checkIntersection( line_sensor[0], line_sensor[1] );
  
  if ( line_1_val < THRESHOLD && line_2_val < THRESHOLD ) {
    Serial.println( "On white" );
    driveForward( motorPin_1_array );
    driveForward( motorPin_2_array );
  } else if ( line_1_val < THRESHOLD && line_2_val > THRESHOLD ) {
    Serial.println( "Line sensor 2 is off " );
    driveForward( motorPin_1_array );
    driveStop( motorPin_2_array );
  } else if ( line_1_val > THRESHOLD && line_2_val < THRESHOLD ) {
    Serial.println( "Line sensor 1 is off " );
    driveForward( motorPin_2_array );
    driveStop( motorPin_1_array );
  } else {
    driveForward( motorPin_1_array );
    driveForward( motorPin_2_array );
  }
  delay( 300 );
  //checkIntersection( LDR1_val, LDR2_val );
  /*if (LDR1_val > THRESHOLD && LDR2_val > THRESHOLD ) {
    return;
  } else if ( LDR1_val > THRESHOLD && LDR2_val < THRESHOLD ) {
    Serial.println( "LDR1 greater " );
  } else if ( LDR1_val < THRESHOLD && LDR2_val > THRESHOLD ){
    Serial.println( "LDR2 greater " );
  }*/
  
  
  /*if( line_1_val > THRESHOLD && line_2_val < THRESHOLD ) {
    Serial.println( "LDR1 above" );
    if( dir == face ) {
      driveForward( motorPin_2_array );
      driveStop( motorPin_1_array );
    } else {
      driveForward( motorPin_1_array );
      driveStop( motorPin_2_array );
    }
  } else if ( LDR1_val < THRESHOLD && LDR2_val > THRESHOLD ) {
    Serial.println( "LDR2 above" );
    if( dir == face ) {
      driveForward( motorPin_1_array );
      driveStop( motorPin_2_array );
    } else {
      driveForward( motorPin_2_array );
      driveStop( motorPin_1_array );
    }
  } else {
    Serial.println( "Yer fine" );
    if ( dir == face ) {
      driveForward( motorPin_1_array );
      driveForward( motorPin_2_array );
    } else {
      driveBackward( motorPin_1_array );
      driveBackward( motorPin_2_array );
    }
  }*/
}

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
}

// Motor control functions

/*void driveSpeed( const int motorPin_array[], byte PWM_val ) {
  analogWrite( motorPin_array[2], PWM_val );
}*/

void driveForward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 1 );
  digitalWrite( motorPin_array[1], 0 );
}

void driveBackward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 1 );
}

void driveStop( const int motorPin_array[] ) {
  //analogWrite( motorPin_array[2], 0 );
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 0 );
}

void changeFace( int dir ){
  face = face + dir;
  if ( face < 0 )
  {
    face = 3;
  } else if ( face > 3 ) {
    face = 0;  
  }
}

void turn( int turn_dir ) {
  //dir is 0 for motor1 cw, motor 2 ccw
  //dir is 1 for motor1 ccw, motor2 cw
  if( !turn_dir ) {
    driveForward( motorPin_1_array );
    driveBackward( motorPin_2_array );
    changeFace(1);
  } else if (turn_dir == 2) {
    return;
  } else { 
    driveBackward( motorPin_1_array );
    driveForward( motorPin_2_array );
    changeFace(-1);
  } 
  
  delay( TURN_TIME );
  driveStop( motorPin_1_array );
  driveStop( motorPin_2_array );
  
}

void catchBall( int servoPin ) {
  
  
}

/*

  Mischief managed

*/
