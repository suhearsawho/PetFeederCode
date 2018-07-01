#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

const int NUM_FEEDINGS = 2;
const int DISPLAY_DELAY = 3000;
String initialTime;
String * feedTimes;

void setup() {
    Serial.begin(9600);
    lcd.begin(16,2);
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
