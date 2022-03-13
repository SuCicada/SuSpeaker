//
// Created by SuCicada on 3/4/2022.
//

#ifndef SUSPEAKER_SPEAKER_H
#define SUSPEAKER_SPEAKER_H

#include "Arduino.h"

int speed = 90;  //higher value, slower notes
void setup() {
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
}

int PLAY_FLAG = 1;

void is_pause() {
    if (Serial.available()) {
        char c = (char) Serial.read();
        String msg = "recive ";
        msg += c;
        Serial.println(msg);
        switch (c) {
            case 'Y':
                PLAY_FLAG = 1;
                break;
            case 'N':
                PLAY_FLAG = 0;
                break;
            default:
                break;
        }
    }
}

int thisNote = 0;

void loop() {
//    Serial.println("ok");
    is_pause();
    if (melody[thisNote] != -1) {
        if (PLAY_FLAG) {
            int noteDuration = speed * noteDurations[thisNote];
            Serial.println(melody[thisNote]);
            tone(3, melody[thisNote],
                 noteDuration * .95);
            delay(noteDuration);
//            noTone(3);
            thisNote++;
        }
    } else {
        thisNote = 0;
    }
}

#endif //SUSPEAKER_SPEAKER_H
