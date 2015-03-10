const int motorPin_1 = 9;
const int motorPin_2 = 10;

void setup () {
  Serial.begin(9600);
  pinMode(motorPin_1, OUTPUT);  
  pinMode(motorPin_2, OUTPUT);
  //digitalWrite(motorPin_1, LOW);
  //digitalWrite(motorPin_2, HIGH );
  digitalWrite(motorPin_1, HIGH);
  digitalWrite(motorPin_2, LOW);
  Serial.println("1: 127");
  delay(10000);
  digitalWrite(motorPin_1, HIGH);
  Serial.println("1: 255");
  delay(10000);
  digitalWrite(motorPin_1, LOW);
  Serial.println("STOP");
  delay(1000);
  digitalWrite(motorPin_2, HIGH);
  Serial.println("2: 127");
  delay(10000);
  digitalWrite(motorPin_2, LOW);  
  //digitalWrite(motorPin_2, LOW);
  Serial.println("DONE HERE DINOSAUR");
}

void loop (){  
}
