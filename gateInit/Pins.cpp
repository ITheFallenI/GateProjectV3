#include "Pins.h"

void Pins::Setup(){ 
    //Decalre input pins
    myMap inputPins[] = {
      {"STOP_BUTTON", STOP_BUTTON},

      {"RESET_NOTOR1_BUTTON", RESET_NOTOR1_BUTTON},
      {"RESET_NOTOR2_BUTTON", RESET_NOTOR2_BUTTON},
    };

    for(int i = 0; i < sizeof(inputPins) - 1; i++){
      pinMode(inputPins[i].value, INPUT_PULLUP);      
    }

    //Decalre output pins
    myMap outputPins[] = {
      {"LOCK_PIN", LOCK_PIN},

      {"MOTOR_2_MAINS", MOTOR_2_MAINS},
      {"MOTOR_2_UP", MOTOR_2_UP},
      {"MOTOR_2_DOWN", MOTOR_2_DOWN},

      {"MOTOR_1_MAINS", MOTOR_1_MAINS},
      {"MOTOR_1_UP", MOTOR_1_UP},
      {"MOTOR_1_DOWN", MOTOR_1_DOWN},
    };

    for(int i = 0; i < sizeof(outputPins) - 1; i++){
      pinMode(outputPins[i].value, OUTPUT);      
      digitalWrite(outputPins[i].value, HIGH);
    }
 
    Serial.println("Pins setup complete!");
}

int Pins::STOPBUTTON(){
  int stopID = STOP_BUTTON;
  return stopID;
}