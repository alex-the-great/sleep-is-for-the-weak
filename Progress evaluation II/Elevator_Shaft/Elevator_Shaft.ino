const int motorPin_1 = 6;
const int motorPin_2 = 1;

void setup () {
  //Serial.begin(9600);
  pinMode(motorPin_1, OUTPUT);  
  pinMode(motorPin_2, OUTPUT);
  
  digitalWrite(motorPin_1, HIGH);
  digitalWrite(motorPin_2, LOW);
  //Serial.println("1: 127");
  
  delay(10000);
  
  digitalWrite(motorPin_2, LOW);  
  //Serial.println("DONE HERE DINOSAUR");
}

void loop (){  
}
