Servo feedServo;

const int feedServoOpen = 45; 
const int feedServoClose = 0;
const int feedingIntervalLength = 40000; //amount of time that food takes to clear from machine.


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

    if (feedingNumber < NUM_FEEDINGS - 1) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Next Feed Time");
        lcd.setCursor(0,1);
        lcd.print(feedTimes[feedingNumber + 1]);
    }
}


void feedCheckSetup(){
    // TRUE = Pet has not been fed
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        feedCheck[i] = true;   
    }
}

