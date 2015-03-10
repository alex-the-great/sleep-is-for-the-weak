

const int pingPin = 6;
const int dangerThresh = 20; 
int leftDistance, rightDistance; //distances on either side
const int motor1[3] = {12,13, 5};
const int motor2[3] = {10,9,3};
const int LED = 22;
long duration; //time it takes to recieve PING))) signal
byte PWM_val = 127;

void setup()
{
   pinMode(motor1[0], OUTPUT);
   pinMode(motor1[1], OUTPUT);
   pinMode(motor1[2], OUTPUT);
   pinMode(motor2[0], OUTPUT);
   pinMode(motor2[1], OUTPUT);
   pinMode(motor2[2], OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int distanceFwd = ping();
  if (distanceFwd>dangerThresh) //if path is clear
  {
    Serial.println("All good!");
    driveForward(motor1);
    driveForward(motor2);
    delay(100);
  }
  else //if path is blocked
  {
    Serial.println("Obstacle Detected");
    driveStop(motor1);
    driveStop(motor2);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    
    driveForward(motor1);
    driveBackward(motor2);
    delay(300);
    driveStop(motor1);
    driveStop(motor2);
    delay(500);
    driveForward(motor1);
    driveForward(motor2);
    int distanceFwd = ping();
    
    if (distanceFwd>dangerThresh) //if path is clear
    {
      Serial.println("Good to the right");
      driveForward(motor1);
      driveForward(motor2);
      delay(100);
    }
    else{
      Serial.println("Obstacle to the right");
      driveForward(motor2);
      driveBackward(motor1);
      delay(600);
      int distanceFwd = ping();
      if (distanceFwd>dangerThresh) //if path is clear
      {
        Serial.print("Good to the left");
        driveForward(motor1);
        driveForward(motor2);
        delay(100);
      }
      else{
        Serial.print("Left is blocked too; better spin");
        driveForward(motor2);
        driveBackward(motor1);
        delay(600);
        if (distanceFwd>dangerThresh) //if path is clear
        {
          Serial.print("Path behind is clear");
          driveForward(motor1);
          driveForward(motor2);
          delay(100);
        }
      }
    }
  }
}
      
      
//    driveBackward(motor1);
//    driveBackward(motor2);
//    delay(1000);
//    driveStop(motor1);
//    delay(400);
//    driveStop(motor2);
//    driveForward(motor1);
//    driveForward(motor2);



long ping()
{
  // Send out PING))) signal pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  //Get duration it takes to receive echo
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  //Convert duration into distance
  return duration / 29 / 2;
}

void driveForward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 1 );
  digitalWrite( motorPin_array[1], 0 );
  analogWrite(motorPin_array[2], PWM_val);

}

void driveBackward( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 1 );
  analogWrite(motorPin_array[2], PWM_val);

}

void driveStop( const int motorPin_array[] ) {
  digitalWrite( motorPin_array[0], 0 );
  digitalWrite( motorPin_array[1], 0 );
}
