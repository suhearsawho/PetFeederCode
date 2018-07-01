String getTime() {
    String inputTime;
    for (int i = 0; i < 4; i++) {
        String inputDigit = convertButtonValue(readRemoteButton());

        // Insert ":" between HH and MM
        if (i == 2) {
            inputTime += ":";
        }
        inputTime += inputDigit;
    }
    return inputTime;
}


String * getFeedTimes() {
    static String feedTimes[NUM_FEEDINGS];
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        bool verifyTime;
        do {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Feeding Time ");
            lcd.setCursor(14,0);
            lcd.print(String(i+1));
            feedTimes[i] = getTime();
            lcd.setCursor(0,1);
            lcd.print(feedTimes[i]);
            delay(DISPLAY_DELAY);
            verifyTime = isValidTime(feedTimes[i]);
        } while (!verifyTime);
    }
    return feedTimes;
}


// user enters initial time to IR remote. time must be in 4 digit format. 
String getInitialTime() {  
    bool verifyTime;
    do {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Time?");
        
        String initialTime = getTime();
        
        lcd.setCursor(0,1);
        lcd.print(initialTime);
        delay(DISPLAY_DELAY);
        
        verifyTime = isValidTime(initialTime);
    } while (!verifyTime);
    return initialTime;
}

void verifyFeedTimes(String * feedTimes) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Feed Times at:");
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        lcd.setCursor(i*6,1);
        lcd.print(feedTimes[i]);
    }
    delay(DISPLAY_DELAY);
}

String getCurrentTime() {
    return "0";
}

