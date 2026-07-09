int largestAltitude(int* gain, int gainSize) {
    int currentAltitude = 0;
    int maxAltitude = 0;

    for (int i = 0; i < gainSize; i++) {
        currentAltitude += gain[i];

        if (currentAltitude > maxAltitude) {
            maxAltitude = currentAltitude;
        }
    }

    return maxAltitude;
}