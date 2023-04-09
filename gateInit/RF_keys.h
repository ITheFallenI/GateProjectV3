#ifndef RF_KEYS_H
#define RF_KEYS_H
#include <Arduino.h>

class RF_keys{

  private:
    int lastKeyPressCount = 0;

    int m_KeyA = 5;
    int m_KeyB = 4; 
    int m_KeyC = 2;
    int m_KeyD = 3;

  public:
    RF_keys();
    bool getKeyDown(int pin);  
    int ReturnKeyPressCount();

    int KEY_A();
    int KEY_B();
    int KEY_C();
    int KEY_D();
};
#endif
