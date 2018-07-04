Servo feedServo;

const int feedServoOpen = 45; 
const int feedServoClose = 0;
const int feedingIntervalLength = 40000; //amount of time that food takes to clear from machine.


void feedFood(int feedingNumber){
    feedServo.writeMicroseconds(map(feedServoOpen,0,180,0,2000));
    delay(feedingIntervalLength);
    feedServo.writeMicroseconds(map(feedServoClose, 0,180,0,2000));
    feedCheck[feedingNumber] = false;
    Serial.println("CAT HAS BEEN FED!");
}


void feedCheckSetup(){
    for (int i = 0; i < NUM_FEEDINGS; i++) {
        feedCheck[i] = true;   
    }
}

