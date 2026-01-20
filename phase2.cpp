#include <iostream>
using namespace std;

/* Trip States as NUMBERS (old compiler friendly) */
#define REQUESTED 0
#define ASSIGNED 1
#define ONGOING 2
#define COMPLETED 3

/* Driver */
class Driver {
public:
    int id;
    int available;

    Driver(int i) {
        id = i;
        available = 1;   // 1 = true
    }
};

/* Rider */
class Rider {
public:
    int id;

    Rider(int i) {
        id = i;
    }
};

/* Trip */
class Trip {
public:
    int id;
    int riderId;
    int driverId;
    int state;

    Trip(int t, int r) {
        id = t;
        riderId = r;
        driverId = -1;
        state = REQUESTED;
    }
};

int main() {

    Driver d1(1);
    Rider r1(101);
    Trip t1(1001, r1.id);

    cout << "Trip State: REQUESTED" << endl;

    // Assign Driver
    if (d1.available == 1) {
        t1.driverId = d1.id;
        t1.state = ASSIGNED;
        d1.available = 0;
        cout << "Driver Assigned. State: ASSIGNED" << endl;
    }

    // Start Trip
    if (t1.state == ASSIGNED) {
        t1.state = ONGOING;
        cout << "Trip Started. State: ONGOING" << endl;
    }

    // Complete Trip
    if (t1.state == ONGOING) {
        t1.state = COMPLETED;
        d1.available = 1;
        cout << "Trip Completed. State: COMPLETED" << endl;
    }

    return 0;
}
