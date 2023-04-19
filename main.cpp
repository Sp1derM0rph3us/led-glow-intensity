// C++ cod
// Created by sp1d3rm0rph3us

const int led = 3; // defining in wich port the led is connected to
int value = 0; // Creating a variable for the ammount of power

void setup()
{
  Serial.begin(9600);	// Default serial port voltage
  pinMode(led,OUTPUT);	// Defining the function of the pin, in this case it is an output port for the LED
  // Startup message
  Serial.println(String("Hello and welcome to my project. Insert a integer number from 0 to 255 to see the LED's glow increase or decrease!"));
}

void loop()
{
  if (Serial.available() > 0) {	// If the value of "value" variable is bigger than zero
    value = Serial.parseInt();
    if(value <= 255) {		// Checks if the value of it isn't bigger than 255
      analogWrite(led, value);		// Writes the value "to" the LED
      Serial.println(String("LED power: ") + value);	// Outputs LED's power
    }
    else{   // What happens if the value is bigger than 255
      analogWrite(led, 0);
      Serial.println(String("You've inserted a value bigger than the allowed, setting LED's power to 0."));
    }
  }
}
