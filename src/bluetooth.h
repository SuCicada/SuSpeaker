//
// Created by SuCicada on 3/6/2022.
//

#ifndef SUSPEAKER_BLUETOOTH_H
#define SUSPEAKER_BLUETOOTH_H

#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    while (Serial.available()) {
        char c = Serial.read();
        String msg = "recive ";
        msg += c;
        Serial.println(msg);
        if (c == 'A') {
            Serial.println("Hello I am amarino");
        }
    }
}


#endif //SUSPEAKER_BLUETOOTH_H
