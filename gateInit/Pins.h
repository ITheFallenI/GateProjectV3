#ifndef PINS_H
#define PINS_H
#include <Arduino.h>

class Pins{
  #define LOCK_PIN 6
  #define STOP_BUTTON 7
  
  #define RESET_NOTOR1_BUTTON 10
  #define RESET_NOTOR2_BUTTON 47
  
  #define MOTOR_2_MAINS 31 //13  //mains power to motor #1
  #define MOTOR_2_UP 29     //mains to motor #1 up
  #define MOTOR_2_DOWN 34   //mains to motor #1 up
  
  #define MOTOR_1_MAINS 25  //mains power to motor #1
  #define MOTOR_1_UP 23      //mains to motor #1 up
  #define MOTOR_1_DOWN 27    //mains to motor #1 up


  private:
    struct myMap{
      String key;
      int value;
    };

  public:
    void Setup();
    int STOPBUTTON();

};

#endif