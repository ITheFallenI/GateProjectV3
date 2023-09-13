#ifndef MEMORY_H
#define MEMORY_H

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

class Memory{
  private:
    int pinCS = 53;
    String ReadDataSD();
    void WriteDataSD(int number);

  public:
    void SetGateDataStateClosed(){ 
      WriteDataSD(21); 
    }

    void SetGateDataStateOpen(){ 
      WriteDataSD(12); 
    }

    bool returnBool(char state){
      switch(state){
        case '2':
          return false;
        case '1': 
          return true;
        default:
          return false;
      }
    }
};
#endif