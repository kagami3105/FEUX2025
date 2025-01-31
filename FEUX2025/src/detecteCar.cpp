#include <Arduino.h>
#include "Timer.h"
#include "FeuxTricolore.h"
#include "sound.h"
#include "detecteCar.h"

DetecteCar::DetecteCar(int cpt) : sensor(cpt) {
    pinMode(sensor, INPUT);
}

bool DetecteCar::is_car() {
    digitalRead(sensor) == HIGH ? true : false;
    return (true);
}
