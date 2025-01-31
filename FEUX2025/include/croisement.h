#ifndef CROISEMENT_H
#define CROISEMENT_H

#include <Arduino.h>
#include "Timer.h"
#include "FeuxTricolore.h"
#include "sound.h"
#include "detecteCar.h"

#pragma once

class Croisement
{
private:
    FeuxTricolore firstlight;
    FeuxTricolore secondlight;
    FeuxTricolore thirdlight;
    FeuxTricolore fourlight;
    Sound sound;
    DetecteCar isSensor;
    unsigned long isTime;
    int myHour;
    int my_changeFunc();


public:
    Croisement(int rouge1, int orange1, int vert1, int rouge2, int orange2, int vert2, int rouge3, int orange3, int vert3, int rouge4, int orange4, int vert4, int brocheSound, int brocheSensor);
    int startFire();
    int updateFire();
    int pastFire();
};


#endif // CROISEMENT_H