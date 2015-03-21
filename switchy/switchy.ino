const int switchyL = 7;
const int switchyR = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(switchyL, INPUT);
  pinMode(switchyR, INPUT);
  
}
void loop()
{
  int Lval = digitalRead(switchyL);
  int Rval = digitalRead(switchyR);
  Serial.print("Left: ");
  Serial.println(Lval);
  Serial.print("Right: ");
  Serial.println(Rval);
  delay(100);
}
