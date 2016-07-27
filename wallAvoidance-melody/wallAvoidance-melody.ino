#include <Sparki.h> // include the sparki library
#include "pitches.h"

// notes in the melody:
int melody[] = { NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 8, 8, 8, 4, 8, 2 };

void setup() {
  sparki.servo(SERVO_CENTER); // Center the Servo
}

void loop()
{
    sparki.RGB(RGB_GREEN); // turn the light green
    sparki.moveForward(); // move Sparki forward
    int cm = sparki.ping(); // measures the distance with Sparki's eyes
        
    if(cm != -1) // make sure its not too close or too far
    { 
        if(cm < 20) // if the distance measured is less than 10 centimeters
        {
            sparki.RGB(RGB_RED); // turn the light red
            playMelody();
            sparki.moveBackward(10); // back up 10 centimeters
            sparki.moveRight(30); // rotate right 30 degrees
        }
    }
    delay(100); // wait 0.1 seconds (100 milliseconds)
}

void playMelody() 
{
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // calculate the note duration as 1 second divided by note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    sparki.beep(melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    sparki.noBeep();
  }
}

