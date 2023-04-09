#ifndef GATES_H
#define GATES_H
#include <Arduino.h>
#include "Timer.h"
#include "RF_keys.h"
#include "Pins.h"
#include "Motors.h"

enum GateState {
  GateClosed,
  GateOpened,
  MUSTSTOP
};

class Gates{

  private:
    Motors motors;
    Pins pins;
    Timer OpenTimer;
    Timer CloseTimer;

  public: 
    GateState gateState = GateClosed;

    void OpenGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock);
    void EmergencyStop();

};

#endif