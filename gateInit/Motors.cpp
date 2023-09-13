#include "Motors.h"
#include "Pins.h"

//Motor 1 functions.

void Motors::OpenMotor_1_On(){
  ToggleRelay(MOTOR_1_MAINS, MOTOR_1_UP);
}

void Motors::OpenMotor_1_Off(){
  ToggleRelay(MOTOR_1_MAINS, MOTOR_1_UP);
}

void Motors::CloseMotor_1_On() {
  ToggleRelay(MOTOR_1_MAINS, MOTOR_1_DOWN);
}
 
void Motors::CloseMotor_1_Off() {
  ToggleRelay(MOTOR_1_MAINS, MOTOR_1_DOWN);
}


//Motor 2 functions.

void Motors::OpenMotor_2_On(){
  ToggleRelay(MOTOR_2_MAINS, MOTOR_2_UP);
}

void Motors::OpenMotor_2_Off(){
  ToggleRelay(MOTOR_2_MAINS, MOTOR_2_UP);
}

void Motors::CloseMotor_2_On() {
  ToggleRelay(MOTOR_2_MAINS, MOTOR_2_DOWN);
}
 
void Motors::CloseMotor_2_Off() {
  ToggleRelay(MOTOR_2_MAINS, MOTOR_2_DOWN);
}

// Other Functions.

bool Motors::ValidEmergencyStop(){ 
  return MOTOR_1_UP_BOOL == true || MOTOR_1_DOWN_BOOL == true || MOTOR_2_UP_BOOL == true || MOTOR_2_DOWN_BOOL == true; 
}

void Motors::ToggleRelay(int pinID_1, int pinID_2)
{
  //process pinID_1
  digitalWrite(pinID_1, !digitalRead(pinID_1));
  ToggleBools(pinID_1);

  //process pinID_2
  digitalWrite(pinID_2, !digitalRead(pinID_2));
  ToggleBools(pinID_2);
}

void Motors::ToggleBools(int pinID)
{
    switch(pinID){
      case MOTOR_1_MAINS:
        MOTOR_1_MAINS_BOOL = !MOTOR_1_MAINS_BOOL;
        break; 
      case MOTOR_1_UP:
        MOTOR_1_UP_BOOL = !MOTOR_1_UP_BOOL;
        break; 
    }
}

void Motors::TurnOffAll(){
  OpenMotor_1_Off();
  CloseMotor_1_Off();

  OpenMotor_2_Off(); 
  CloseMotor_2_Off();
}