String * getFeedTimes() {
    static String feedTimes[NUM_FEEDINGS];
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Feeding Time ");
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        lcd.setCursor(14,0);
        lcd.print(String(i+1));
        feedTimes[i] = getTime();
        lcd.setCursor(0,1);
        lcd.print(feedTimes[i]);
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


String getCurrentTime() {
    return "0";
}

