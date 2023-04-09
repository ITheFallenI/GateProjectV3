#include "Gates.h"

void Gates::OpenGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock)
{
    Serial.println("Open gates init.");
    
    unsigned int fullOpenTime = m_delayForLock + m_leftGateOpeningTime + (m_rightGateOpeningTime - (m_rightGateOpeningTime - m_delayBetweenOpening)) + 1000;
    
    OpenTimer.start();
    gateState = GateClosed;

    while (OpenTimer.isRunning()){      
        if(OpenTimer.elapsed() == m_delayForLock){      
            Serial.println("delayForLock: Disabled lock.");
            Serial.println("Start Motor 1 : " + OpenTimer.elaspedTimeString());
        }

        if(OpenTimer.elapsed() == m_delayForLock + m_delayBetweenOpening){      
            Serial.println("Start Motor 2 : " +  OpenTimer.elaspedTimeString());
        }

        if(OpenTimer.elapsed() == m_delayForLock + m_leftGateOpeningTime){      
            Serial.println("Stop Motor 1 : " +  OpenTimer.elaspedTimeString());
        }

        if(OpenTimer.elapsed() == m_delayForLock + m_rightGateOpeningTime + m_delayForLock){
            Serial.println("Stop Motor 2 : " +  OpenTimer.elaspedTimeString());
        }

        if(OpenTimer.elapsed() == fullOpenTime){      
          Serial.println("fullOpenTime mark : " + OpenTimer.elaspedTimeString());    
          OpenTimer.stop(); 
          OpenTimer.reset();       
          gateState = GateOpened;
        }
    }
}

void Gates::EmergencyStop(){
    if(motors.ValidEmergencyStop()){   
        Serial.println("Called emergency stop function.");
        //turn off all motors
        gateState = MUSTSTOP;
    }else{
      Serial.println("No motors on no point to emergency stop.");
    }
}
