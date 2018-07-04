#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Servo.h>

#include <Time.h>
#include <TimeLib.h>

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

const int NUM_FEEDINGS = 2;
const int DISPLAY_DELAY = 2000;
String initialTime;
String * feedTimes;
bool * feedCheck;

void setup() {
    Serial.begin(9600);
    lcd.begin(16,2);
    setupRemote();
    initialTime = setInitialTime();
    feedTimes = getFeedTimes();
    verifyFeedTimes(feedTimes);
    feedCheck = feedCheckSetup();
}

void loop() {
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        if (*(feedTimes + i) == getCurrentTime()) {
            if (*(feedCheck + i) == true) {
                feedFood(i);
            }
            else {
                Serial.println("YOU'RE CAT HAS ALREADY BEEN FED!");
            }
        }
    }
    Serial.println(getCurrentTime());
    delay(1000);
}
