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
      
const int DISPLAY_DELAY = 2000;
String initialTime;
String * feedTimes;
bool * feedCheck;
int numFeedings;

void setup() {
    Serial.begin(9600);
    lcd.begin(16,2);
    
    setupRemote();
    
    initialTime = setInitialTime();
    numFeedings = setNumFeedings();
    feedTimes = getFeedTimes();
    verifyFeedTimes(feedTimes);
    feedCheckSetup();
}

void loop() {
    for (int i = 0; i < numFeedings; i++) {
        if (*(feedTimes + i) == getCurrentTime()) {
            if (*(feedCheck + i) == true) {
                feedFood(i);
            }
        }
        
        if ( i == numFeedings - 1) {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Feedings");
            lcd.setCursor(0,1);
            lcd.print("Complete"); 
        }
    }
    

    if (getCurrentTime() == "00:00") {
        feedCheckSetup();
    }
}
