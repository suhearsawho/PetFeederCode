// ALL TIME VALUES MUST BE ENTERED IN 4 UNITS. HH, MM. 
// VALUES ARE DISPLAYED IN 24 HOUR UNITS 


// foundation for functions that involve getting time values from user
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


// user inputs the various feeding times for pet
String * getFeedTimes() {
    String feedTimes[numFeedings];
    for (int i = 0; i < numFeedings; i++) {
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
String setInitialTime() {  
    String initialTime;
    bool verifyTime;
    
    do {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Time?");
        
        initialTime = getTime();
        
        lcd.setCursor(0,1);
        lcd.print(initialTime);
        delay(DISPLAY_DELAY);
        
        verifyTime = isValidTime(initialTime);
    } while (!verifyTime);

    // convert string initial time to integers. input time integers into time library function - setTime()
    int hourTime = initialTime.substring(0,2).toInt();
    int minuteTime = initialTime.substring(3,5).toInt();
    setTime(hourTime,minuteTime,0,7,4,2018);

    return initialTime;
}


bool isValidTime(String inputTime) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Confirm?");
    lcd.setCursor(0,1);
    lcd.print(inputTime);

    // Only accept Yes or No buttons
    do {
        String verifyInput = readRemoteButton();
    
        Serial.println(verifyInput);
        if (verifyInput == REMOTE_FORWARD) {
            lcd.setCursor(6,1);
            lcd.print("Yes");
            delay(DISPLAY_DELAY);
            return true;
        } else if (verifyInput == REMOTE_REVERSE) {
            lcd.setCursor(6,1);
            lcd.print("No");
            delay(DISPLAY_DELAY);
            return false;
        }
    } while (true);
}


void verifyFeedTimes(String * feedTimes) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Feed Times at:");
    for (int i = 0; i < numFeedings; i++) {
        lcd.setCursor(i*6,1);
        lcd.print(feedTimes[i]);
    }
    delay(DISPLAY_DELAY);
}


String getCurrentTime() {
    time_t t = now();
    String hourCurrentTime = String(hour(t));
    String minuteCurrentTime = String(minute(t));

    int lengthHour = hourCurrentTime.length();
    if (lengthHour < 2) {
        hourCurrentTime = "0" + hourCurrentTime;
    }
    int lengthMinute = minuteCurrentTime.length();
    if (lengthMinute < 2) {
        minuteCurrentTime = "0" + minuteCurrentTime;
    }

    String currentTime = hourCurrentTime + ":" + minuteCurrentTime;
    return currentTime;
}


