int * getFeedTimes() {
    static int feedTimes[NUM_FEEDINGS];
    for (int i = 0; i < NUM_FEEDINGS; i++) {
      feedTimes[i] = 0;
    }
    return feedTimes;
}

int getInitialTime() {
    return 0;
}

int getCurrentTime() {
    return 0;
}

