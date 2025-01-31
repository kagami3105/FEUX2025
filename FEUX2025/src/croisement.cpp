#include <Arduino.h>
#include "Timer.h"
#include "FeuxTricolore.h"
#include "croisement.h"
#include "detecteCar.h"

Croisement::Croisement(int rouge1, int orange1, int vert1, int rouge2, int orange2, int vert2, int rouge3, int orange3, int vert3, int rouge4, int orange4, int vert4, int brocheSound, int brocheSensor)
    : firstlight(rouge1, orange1, vert1), secondlight(rouge2, orange2, vert2), thirdlight(rouge3, orange3, vert3), fourlight(rouge4, orange4, vert4), sound(brocheSound), isSensor(brocheSensor), isTime(0), myHour(5000)
{
}

int Croisement::startFire()
{
    firstlight.openRed();
    secondlight.openRed();
    thirdlight.openGreen();
    fourlight.openRed();
    isTime = millis();
    return (0);
}

int Croisement::updateFire()
{
    unsigned long timeStart = millis();
    int a = 0;
    if (timeStart - isTime >= myHour)
    {
        a = my_changeFunc();
        isTime = timeStart;
    }

    if (isSensor.is_car())
    {
        myHour = 3000;
    }
    else
    {
        myHour = 5000;
    }
    return (0);
}

int Croisement::my_changeFunc()
{
    if (thirdlight.turnOn())
    {
        thirdlight.openOrange();
        sound.arlert(500);
        delay(2000);
        thirdlight.openRed();
        firstlight.openGreen();
    } else if (firstlight.turnOn())
    {
        firstlight.openOrange();
        sound.arlert(500);
        delay(2000);
        firstlight.openRed();
        thirdlight.openGreen();

    }
    return(0);
    
}