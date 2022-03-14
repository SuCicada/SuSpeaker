//
// Created by Administrator on 3/13/2022.
//

#ifndef SUSPEAKER_SD_MY_H
#define SUSPEAKER_SD_MY_H

#include <Arduino.h>
#include <SD.h>                           //include SD module library
#include <TMRpcm.h>                       //include speaker control library

#define SD_ChipSelectPin 10                //define CS pin

TMRpcm tmrpcm;                            //crete an object for speaker library

void setup() {
//    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

//    delay(5000);
    tmrpcm.speakerPin = 9;                  //define speaker pin.
    //you must use pin 9 of the Arduino Uno and Nano
    //the library is using this pin

    Serial.println("start");
    if (!SD.begin(SD_ChipSelectPin)) {      //see if the card is present and can be initialized
        Serial.println("error");
//        for (int i = 0; i < 10; i++) {
//            digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//            delay(500);                       // wait for a second
//            digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//        }
        return;                               //don't do anything more if not
    }

    tmrpcm.setVolume(6);                    //0 to 7. Set volume level
    //the sound file "1" will play each time the arduino powers up, or is reset
    tmrpcm.play("beg.wav");
}

void loop() {

}


#endif //SUSPEAKER_SD_MY_H
