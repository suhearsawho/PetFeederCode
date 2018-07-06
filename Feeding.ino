Servo feedServo;

const int feedServoOpen = 45;   // in terms of degrees
const int feedServoClose = 0;   // in terms of degrees
const int feedingIntervalLength = 40000; //amount of time that food takes to clear from machine.


int setNumFeedings() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("# Feed Times?");

    String numFeedingsString = convertButtonValue(readRemoteButton());
    isValidTime(numFeedingsString);
    int numFeedings = numFeedingsString.toInt();
    
    return numFeedings;
}


void feedFood(int feedingNumber){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Feeding Time");
    lcd.setCursor(0,1);
    lcd.print(feedTimes[feedingNumber]);
    
    feedServo.writeMicroseconds(map(feedServoOpen,0,180,0,2000));
    delay(feedingIntervalLength);
    feedServo.writeMicroseconds(map(feedServoClose, 0,180,0,2000));
    
    feedCheck[feedingNumber] = false;

    if (feedingNumber < numFeedings - 1) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Next Feed Time");
        lcd.setCursor(0,1);
        lcd.print(feedTimes[feedingNumber + 1]);
    }
}


void feedCheckSetup(){
    // TRUE = Pet has not been fed
    bool feedCheck[numFeedings];
    for (int i = 0; i < numFeedings; i++) {
        feedCheck[i] = true;   
    }
}

