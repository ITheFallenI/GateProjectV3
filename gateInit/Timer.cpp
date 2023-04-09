#include "Timer.h"

Timer::Timer() {
  startTime = 0;
  running = false;
}

void Timer::start() {
  startTime = millis();
  running = true;
}

void Timer::stop() {
  running = false;
}

void Timer::reset() {
  startTime = 0;
  running = false;
}

unsigned long Timer::elapsed() {
  if (running) {
    return millis() - startTime;
  }
  else {
    return 0;
  }
}

bool Timer::isRunning() {
  return running;
}

String Timer::elaspedTimeString(){
  return String(elapsed());
}