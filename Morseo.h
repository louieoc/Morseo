/*
  Morseo.h - Library for blinking Morse code.
  Created by Louis O'Callaghan 2014
  http://louisocallaghan.com
  Released into the public domain.
*/
#ifndef Morseo_h
#define Morseo_h

#include "Arduino.h"

// dots, dashes and relative time units as per the international standard
// http://en.wikipedia.org/wiki/Morse_code

// this determines the keying speed
int const timeUnit = 200;
int const dot = timeUnit;
int const dash = timeUnit * 3;
int const keySpace = timeUnit;
int const charSpace = timeUnit * 3;
int const wordSpace = timeUnit * 7;
int const messageSpace = wordSpace * 2; // not a standard, as far as I know
int const maxMorseLength = 6; // no more than 6 dots or dashes per character

typedef void (*keyCharacter)(char);

class Morseo
{
  public:
    Morseo(int pin);	
    void keyMessage(const char *message, keyCharacter callback = NULL);
    void getMorse(char character, char *buffer);
  private:
    int _pin;
    void keyCharacterToPin(char letter);
    void keyPin(int milliseconds);
    void getMorseNumber(char const number, char *buffer);
};

#endif
