/*
  Writes a message in morse code to an LoLShield; displays each letter on
  the left side of the shield while the dashes and dots blink on the right side.
  
  Adapted from the "Blink" example, among others, by Louis O'Callaghan 2014-2015
  http://louisocallaghan.com
  Released into the public domain.
 */
 
#include <Morseo.h>
#include "Charliplexing.h"
#include "Font.h"
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int const output = 13;
int const letterXValue = 1;
int const dotDashXValue = 8;

Morseo morseo(output);

// the setup routine runs once when you press reset:
void setup() {                
  LedSign::Init();
  LedSign::SetBrightness(10);
}

// the loop routine runs over and over again forever:
void loop() {
  morseo.keyMessage("0 1 2 3 4 5 6 7 8 9 the quick brown fox jumped over the lazy dog . , / @ ?", keyCharacterToLolShield);
}

void keyCharacterToLolShield(char letter)
{
  // translate the character into a string of morse dashes and dots
  char morseString[maxMorseLength + 1]; // plus 1 for the null character
  morseo.getMorse(letter, morseString);
  
  // font library doesn't seem to allow me lowercase, so make sure the character is uppercase
  if (letter > 96 && letter < 123)
    letter -= 32;
  
  int i = 0;
  while (morseString[i] != '\0')
  {
    // first, draw the letter we're keying to the left side of the display
    LedSign::Clear();
    Font::Draw(letter, letterXValue, 0);
    
    // draw the morse dot or dash to the right side of the display
    if (morseString[i] == '.')
    {
      Font::Draw('.', dotDashXValue+1, -3);
      delay(dot);
    }
    else if (morseString[i] == '-')
    {
      Font::Draw('-', dotDashXValue, 0);
      delay(dash);
    }
    
    // to clear the dot or dash need to clear the whole display
    LedSign::Clear();

    // if this isn't end of string then re-display the letter we're still keying and wait a bit
    if (morseString[++i] != '\0')
    {
      Font::Draw(letter, letterXValue, 0);
      delay(keySpace);
    }
  }
  free(morseString);
}
