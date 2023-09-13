#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>

class Motors{

  private: 
    bool MOTOR_1_MAINS_BOOL;
    bool MOTOR_1_UP_BOOL;
    bool MOTOR_1_DOWN_BOOL;

    bool MOTOR_2_MAINS_BOOL;
    bool MOTOR_2_UP_BOOL;
    bool MOTOR_2_DOWN_BOOL;

    void ToggleRelay(int pinID_1, int pinID_2);
    void ToggleBools(int pinID);

  public:
    bool ValidEmergencyStop();

    void OpenMotor_1_On();
    void OpenMotor_1_Off();
    void CloseMotor_1_On();  
    void CloseMotor_1_Off();

    void OpenMotor_2_On();
    void OpenMotor_2_Off();
    void CloseMotor_2_On();  
    void CloseMotor_2_Off();

    void TurnOffAll();
};

#endif