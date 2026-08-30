#define MAX 1000

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval bookings[MAX];
    int bookingCount;

    Interval overlaps[MAX];
    int overlapCount;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = malloc(sizeof(MyCalendarTwo));

    obj->bookingCount = 0;
    obj->overlapCount = 0;

    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int startTime, int endTime) {

    // Step 1: Check whether this creates a triple booking
    for (int i = 0; i < obj->overlapCount; i++) {

        int start = obj->overlaps[i].start;
        int end = obj->overlaps[i].end;

        // Check overlap
        if (startTime < end && endTime > start) {
            return false;
        }
    }

    // Step 2: Find new double-booked intervals
    for (int i = 0; i < obj->bookingCount; i++) {

        int start = obj->bookings[i].start;
        int end = obj->bookings[i].end;

        int overlapStart = startTime > start ? startTime : start;
        int overlapEnd = endTime < end ? endTime : end;

        if (overlapStart < overlapEnd) {
            obj->overlaps[obj->overlapCount].start = overlapStart;
            obj->overlaps[obj->overlapCount].end = overlapEnd;

            obj->overlapCount++;
        }
    }

    // Step 3: Store the new booking
    obj->bookings[obj->bookingCount].start = startTime;
    obj->bookings[obj->bookingCount].end = endTime;

    obj->bookingCount++;

    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj);
}