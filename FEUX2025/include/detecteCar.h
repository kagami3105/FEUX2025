#ifndef DETECT_CAR_H
#define DETECTE_CAR_H

#pragma once

class DetecteCar
{
private:
    int sensor;

public:
    DetecteCar(int cpt);
    bool is_car();
};

#endif // DETECTE_CAR_H