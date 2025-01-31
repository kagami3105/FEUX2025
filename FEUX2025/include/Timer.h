#ifndef TIMER_H
#define TIMER_H

#pragma once

class Timer
{
private:
    unsigned long timerStart;
    unsigned long timerTarget;

public:
    Timer();

    void startTimer(int msec);

    bool isTimerReady();
};

#endif // TIMER_H