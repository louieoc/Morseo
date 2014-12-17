/*
  writes a message in morse code
  (adapted from the "Blink" example - Louis O'Callaghan Jan 2013-Nov 2014)
 */
 
#include <Morseo.h>
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int const output = 13;
Morseo morseo(output);

// the setup routine runs once when you press reset:
void setup() {                
}

// the loop routine runs over and over again forever:
void loop() {
  morseo.keyMessage("0 1 2 3 4 hello world");
}

