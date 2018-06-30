#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <SoftwareSerial.h>

const int NUM_FEEDINGS = 2;
int initialTime;
int* feedTimes;

void setup() {
    Serial.begin(9600);
    setupRemote();
    initialTime = getInitialTime();
    feedTimes = getFeedTimes();
}

void loop() {
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        if (*(feedTimes + i) == getCurrentTime()) {
            feedFood();
        }
    }
}
