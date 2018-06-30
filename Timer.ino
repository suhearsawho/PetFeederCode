String * getFeedTimes() {
    static String feedTimes[NUM_FEEDINGS];
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        feedTimes[i] = "0";
    }
    return feedTimes;
}


// user enters initial time to IR remote. time must be in 4 digit format. 
String getInitialTime() {  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Current Time?");
    String initialTime;
    for (int i = 0; i < 4; i++) {
        String inputDigit = convertButtonValue(readRemoteButton());
        // Holding a button sends REMOTE_REPEAT code.
        // Ignore these and only accept valid digits between 0 from 9.
        if (inputDigit == REMOTE_REPEAT) {
            i--;
            continue;
        }

        // Insert ":" between HH and MM
        if (i == 2) {
            initialTime += ":";
        }
        initialTime += inputDigit;
    }
    lcd.setCursor(0,1);
    lcd.print(initialTime);
    return initialTime;
}

String getCurrentTime() {
    return "0";
}

