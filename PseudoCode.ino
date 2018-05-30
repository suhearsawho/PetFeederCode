// declare variables for 
    // load sensor setup
    // servomotors
    // gyroscope 
    // user interface - LED display and buttons

void pseudo_setup() {
    // Serial Monitor
    // setup pin modes 
}

void pseudo_loop() {
    // check whether autofeed button is on or off   
        // if autofeed button is on
            // check user input (use interupt pin for user input in case something changes in the middle of the loop)
            // check times that user set (24 hour time)
                // check time every hour. 
                // subtract user time from current time (x) and check again in x minutes
            // when time matches one of the user input times 
                // activate servomotors
                // check load cell reading
                // if current load cell - previous load cell reading = food portion size (determined by user) 
                    // rotate servomotors back to initial position 
        // if autofeed button is off 
            // do nothing 
    
}

