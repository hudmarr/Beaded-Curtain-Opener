#include <Stepper.h>

const int stepsPerRevolution = 2038;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

const int buttonPin = 2; // Define the button pin (you can choose any available digital pin)
//connect one side of the button to pin 2 and one side to ground
const int turnNumber = 15; // Set this number to the number of turns needed
int state = 0; // 0 will be closed and 1 will be open

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as an input with a pull-up resistor
  myStepper.setSpeed(10); // positive turns to the right
  
}

void loop() {
  
  if (digitalRead(buttonPin) == LOW) 
  { // Check if the button is pressed (active LOW)
    
    if(state == 0)// open the baby
    {
      for (int i = 0; i < turnNumber; i++) 
      { // Perform 10 full revolutions
        myStepper.step(stepsPerRevolution);
      }
      state = 1;
    }
    else
    {
      for (int i = 0; i < turnNumber; i++) 
      {
        myStepper.step(-stepsPerRevolution);
      }
      state = 0;
    }
  }
}