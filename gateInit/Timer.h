#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>

class Timer {
  private:
    unsigned long startTime;
    bool running;

  public:
    Timer();
    void start();
    void stop();
    void reset();
    unsigned long elapsed();
    bool isRunning();
    String elaspedTimeString();
};

#endif