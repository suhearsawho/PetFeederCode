#include <Time.h>
#include <TimeLib.h>

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

const int NUM_FEEDINGS = 2;
const int DISPLAY_DELAY = 2000;
String initialTime;
String * feedTimes;

void setup() {
    Serial.begin(9600);
    lcd.begin(16,2);
    setupRemote();
    initialTime = setInitialTime();
    feedTimes = getFeedTimes();
    verifyFeedTimes(feedTimes);
}

void loop() {
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        if (*(feedTimes + i) == getCurrentTime()) {
            feedFood();
            Serial.println("FEEDING TIME");
        }
    }
    Serial.println(getCurrentTime());
    delay(10000);
}
