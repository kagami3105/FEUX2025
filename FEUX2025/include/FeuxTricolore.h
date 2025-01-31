#ifndef FEUX_TRICOLORE_H
#define FEUX_TRICOLORE_H

#pragma once

class FeuxTricolore
{
private:
    int brocheVert;
    int brocheOrange;
    int brocheRouge;
    bool isFeuAllume;

public:
    FeuxTricolore(int FeuxRouge, int FeuxOrange, int FeuxVert);
    int openGreen();
    int openRed();
    int openOrange();
    int turnOff();
    bool turnOn() const;
};

#endif // FEUX_TRICOLORE_H