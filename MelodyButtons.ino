#include "pitches.h"
const int GREEN_LED = 6;
const int BLUE_LED = 10;
const int BUZZER_PIN = 8;
const int BUTTON_GREEN = 2;
const int BUTTON_BLUE = 4;

//Melody 1. (Oda do radosci - Beethoven)
int melody1[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_D4,

  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_C4
};

int durations1[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 8, 2,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 8, 2
};

  void playMelody1(){
  int size = sizeof(durations1) / sizeof(int);
  for (int note = 0; note < size; note++) {
    int duration1 = 1000 / durations1[note];
    tone(BUZZER_PIN, melody1[note], duration1);


    int pauseBetweenNotes = duration1 * 1.30;
    delay(pauseBetweenNotes);

    noTone(BUZZER_PIN);
    }
  }

//Melody 2. (Twinkle Twinkle Little Star)
int melody2[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,

  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,

  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int durations2[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,

  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,

  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void playMelody2(){
  int size = sizeof(durations2) / sizeof(int);

  for (int note = 0; note < size; note++) {

    int duration2 = 1000 / durations2[note];
    tone(BUZZER_PIN, melody2[note], duration2);

    int pauseBetweenNotes = duration2 * 1.30;
    delay(pauseBetweenNotes);

    noTone(BUZZER_PIN);
  }
}

//components

void setup()
{
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
}

void loop(){
  if (digitalRead(BUTTON_BLUE) == LOW){
  digitalWrite(BLUE_LED, HIGH);
  playMelody1();
  digitalWrite(BLUE_LED, LOW);
  }
  if (digitalRead(BUTTON_GREEN) == LOW){
    digitalWrite(GREEN_LED, HIGH);
    playMelody2();
    digitalWrite(GREEN_LED, LOW);
  }
}
