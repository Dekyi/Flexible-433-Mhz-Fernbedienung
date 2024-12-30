/* RF Fernsteuerung für drei Garagentore mit drei Buttons auf ein PIN
*/
 
//Constants
const int yellowLed = 8;
const int redLed    = 7;
const int greenLed  = 4;

//Variables
int buttonValue; //Stores analog value when button is pressed


void setup()
{
	pinMode(yellowLed, OUTPUT);
	pinMode(redLed, OUTPUT);
	pinMode(greenLed, OUTPUT);

  Serial.begin(9600); // Fürs debuggen
}

void loop()
{
	buttonValue = analogRead(A0); //Read analog value from A0 pin
	
	//For 1st button: 931@5V
	if (buttonValue>=926 && buttonValue<=936){
    Serial.println(analogRead(A0)); // Fürs debuggen
		digitalWrite(yellowLed, HIGH);
	}
	//For 2nd button: 839@5V
	else if (buttonValue>=834 && buttonValue<=844){
    Serial.println(analogRead(A0)); // Fürs debuggen
		digitalWrite(redLed, HIGH);
	}
	//For 3rd button: 696@5V
	else if (buttonValue>=691  && buttonValue<=701){
    Serial.println(analogRead(A0)); // Fürs debuggen
		digitalWrite(greenLed, HIGH);
	}

	//No button pressed, turn off LEDs
	else{
		digitalWrite(yellowLed, LOW);
	    digitalWrite(redLed, LOW);
	    digitalWrite(greenLed, LOW);
	}
	delay(100);
}