#include "RF_keys.h"

RF_keys::RF_keys(){
  pinMode(m_KeyA, INPUT_PULLUP);
  pinMode(m_KeyB, INPUT_PULLUP);
  pinMode(m_KeyC, INPUT_PULLUP);
  pinMode(m_KeyD, INPUT_PULLUP);
}

int RF_keys::KEY_A(){
  return m_KeyA;
}

int RF_keys::KEY_B(){
  return m_KeyB;
}

int RF_keys::KEY_C(){
  return m_KeyC;
}

int RF_keys::KEY_D(){
  return m_KeyD;
}

bool RF_keys::getKeyDown(int pin) {
  if (digitalRead(pin) == HIGH) {    
      delay(50);
      if (digitalRead(pin) == HIGH) {
        lastKeyPressCount += 1;
        return true;
      }
  }else{
    lastKeyPressCount = 0;
    return false;
  }
}

int RF_keys::ReturnKeyPressCount(){
  return lastKeyPressCount;
}
