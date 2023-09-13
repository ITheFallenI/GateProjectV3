#include "Gates.h"

void Gates::OpenGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock)
{
    Serial.println("Open gates init.");
    
    //Get timer Time.
    unsigned int fullOpenTime = m_delayForLock + m_leftGateOpeningTime + (m_rightGateOpeningTime - (m_rightGateOpeningTime - m_delayBetweenOpening)) + 1000;
    
    //set memory first.
    memory.SetGateDataStateOpen();
    //Start timer.
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

void Gates::CloseGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock)
{
    Serial.println("Close gates init.");
    
    //Get timer Time.
    unsigned int fullCloseTime = m_delayForLock + m_leftGateOpeningTime + (m_rightGateOpeningTime - (m_rightGateOpeningTime - m_delayBetweenOpening)) + 1000;
    
    //set memory first.
    memory.SetGateDataStateClosed();

    //Start timer.
    CloseTimer.start();
    gateState = GateOpened;

    while (CloseTimer.isRunning()){      
        if(CloseTimer.elapsed() == m_delayForLock){      
            Serial.println("delayForLock: Enable lock.");
            Serial.println("Start Motor 1 : " + CloseTimer.elaspedTimeString());
        }

        if(CloseTimer.elapsed() == m_delayForLock + m_delayBetweenOpening){      
            Serial.println("Start Motor 2 : " +  CloseTimer.elaspedTimeString());
        }

        if(CloseTimer.elapsed() == m_delayForLock + m_leftGateOpeningTime){      
            Serial.println("Stop Motor 1 : " +  CloseTimer.elaspedTimeString());
        }

        if(CloseTimer.elapsed() == m_delayForLock + m_rightGateOpeningTime + m_delayForLock){
            Serial.println("Stop Motor 2 : " +  CloseTimer.elaspedTimeString());
        }

        if(CloseTimer.elapsed() == fullCloseTime){      
          Serial.println("fullCloseTime mark : " + CloseTimer.elaspedTimeString());    
          CloseTimer.stop(); 
          CloseTimer.reset();       
          gateState = GateClosed;
        }
    }
}

void Gates::EmergencyStop(){
    if(motors.ValidEmergencyStop()){   
        Serial.println("Called emergency stop function.");
        motors.TurnOffAll();
        gateState = MUSTSTOP;
    }else{
      Serial.println("No motors on no point to emergency stop.");
    }
}

void Gates::InputLoop(){
   
  if(rf_keys.getKeyDown(rf_keys.KEY_C())){
      Serial.println(rf_keys.ReturnKeyPressCount());
      if(gateState == GateClosed){
        OpenGates(8000, 16600, 16100, 2000);
      }
  }

  if(rf_keys.getKeyDown(pins.STOPBUTTON())){
      //gates.EmergencyStop();
  }

}
