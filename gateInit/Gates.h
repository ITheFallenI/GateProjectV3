#ifndef GATES_H
#define GATES_H

#include <Arduino.h>
#include "Timer.h"
#include "RF_keys.h"
#include "Pins.h"
#include "Motors.h"
#include "Memory.h"

enum GateState {
  GateClosed,
  GateOpened,
  MUSTSTOP
};

class Gates{

  private:
    Memory memory;
    Motors motors;
    Pins pins;
    Timer OpenTimer;
    Timer CloseTimer;
    RF_keys rf_keys;

  public: 
    GateState gateState = GateClosed;

    void OpenGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock);
    void CloseGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock);
    void InputLoop();
    
    void EmergencyStop();

    String ReturnGateState(){
      if(gateState == 0)
        return "GateState is Closed.";
      else if(gateState == 1)
        return "GateState is Opened.";
      else if(gateState == 2)
        return "GateState is MUSTSTOP.";
    }

};

#endif