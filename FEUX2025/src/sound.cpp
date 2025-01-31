#include <Arduino.h>
#include "Timer.h"
#include "FeuxTricolore.h"
#include "sound.h"

// Constructeur pour le son

Sound::Sound(int a) : is_sound(a)
{
    pinMode(is_sound, OUTPUT);
}

int Sound::arlert(int tmp)
{
    int fqr = 1000;
    // Fonction pour jouer la musique
    tone(is_sound, fqr, tmp);
    return (0);
}
