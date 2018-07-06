int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

// these values will vary depending on the type of remote being used. 
const String REMOTE_POWER = "FFA25D";
const String REMOTE_VOL_UP = "FF629D";
const String REMOTE_STOP = "FFE21D";
const String REMOTE_REVERSE = "FF22DD";
const String REMOTE_PLAY_PAUSE = "FF02FD";
const String REMOTE_FORWARD = "FFC23D";
const String REMOTE_DOWN = "FFE01F";
const String REMOTE_VOL_DOWN = "FFA857";
const String REMOTE_UP = "FF906F";
const String REMOTE_EQ = "FF9867";
const String REMOTE_REPT = "FFB04F";
const String REMOTE_0 = "FF6897";
const String REMOTE_1 = "FF30CF";
const String REMOTE_2 = "FF18E7";
const String REMOTE_3 = "FF7A85";
const String REMOTE_4 = "FF10EF";
const String REMOTE_5 = "FF38C7";
const String REMOTE_6 = "FF5AA5";
const String REMOTE_7 = "FF42BD";
const String REMOTE_8 = "FF4AB5";
const String REMOTE_9 = "FF52AD";
const String REMOTE_REPEAT = "FFFFFFFF";

void setupRemote() {
    irrecv.enableIRIn(); // Start the receiver
}


// return the value of one button on the IR Remote in HEX form. 
String readRemoteButton() { 
    String input;
    while (true) {
        if(irrecv.decode(&results)) {                   
            input = String(results.value, HEX);
            input.toUpperCase();
            irrecv.resume();
            
            // Holding a button sends REMOTE_REPEAT code.
            // Ignore these and only accept valid digits between 0 from 9.
            if (input != REMOTE_REPEAT) {         
                break;
            }
        }
    }
    return input; 
}


//convert the HEX code from the remote into a string value
String convertButtonValue(String buttonHEX) {
    if (buttonHEX == REMOTE_0) {
        return "0";
    } else if (buttonHEX == REMOTE_1) {
        return "1";
    } else if (buttonHEX == REMOTE_2) {
        return "2";
    } else if (buttonHEX == REMOTE_3) {
        return "3";
    } else if (buttonHEX == REMOTE_4) {
        return "4";
    } else if (buttonHEX == REMOTE_5) {
        return "5";
    } else if (buttonHEX == REMOTE_6) {
        return "6";
    } else if (buttonHEX == REMOTE_7) {
        return "7";
    } else if (buttonHEX == REMOTE_8) {
        return "8";
    } else if (buttonHEX == REMOTE_9) {
        return "9";
    } else {
        return buttonHEX;
    }
}


