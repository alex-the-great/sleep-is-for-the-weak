//Arduino line following
int x = 0;
int y = 0;
int my_position[2] = {x,y}; //x,y

int leftInput=A3;
int rightInput=A4;
// int leftMotor=13;
// int rightMotor=12;
int leftValue = 0;
int rightValue = 0;

void setup() {
	Serial.begin(9600);
	// pinMode (leftMotor, OUTPUT);
        // pinMode (rightMotor, OUTPUT);
}
//only in the y direction for now.
void loop () {
	
	Serial.print("x: ");
	Serial.print(x);
	Serial.print(" y: ");
	Serial.println(y);
	
	leftValue = analogRead (leftInput);
        rightValue= analogRead (rightInput);
        Serial.println(leftValue);
        Serial.println(rightValue);
	
	if( leftValue > 900 && rightValue > 900) {
	// intersection detected
	     y += 1;
             while(leftValue > 900 || rightValue > 900)
             {
               leftValue = analogRead (leftInput);
               rightValue= analogRead (rightInput);
             }
	}
	
	/* if( leftValue < 945 && rightValue < 945) {
		digitalWrite (leftMotor, HIGH);
		digitalWrite (rightMotor, HIGH);
    } else {
		if ( leftValue > 945 && rightValue < 945) {
			digitalWrite (leftMotor, LOW);
			digitalWrite (rightMotor, HIGH);
		} else {
			if (leftValue < 945 && rightValue > 945) {
			digitalWrite (rightMotor, LOW);
			digitalWrite (leftMotor, HIGH);
			} else {
				if (leftValue > 945 && rightValue > 945) {
				digitalWrite (rightMotor, LOW);
				digitalWrite (leftMotor, LOW);
				}
			}
		}
	} */

}
