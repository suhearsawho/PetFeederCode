int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

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
            break;
        }
    }
    return input; 
}

