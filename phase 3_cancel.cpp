#include <iostream>
using namespace std;

/* Trip States */
#define REQUESTED 0
#define ASSIGNED 1
#define ONGOING 2
#define COMPLETED 3
#define CANCELLED 4

/* Driver */
class Driver {
public:
    int id;
    int available;

    Driver(int i) {
        id = i;
        available = 1;
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

    cout << "Trip Created. State: REQUESTED" << endl;

    /* Assign Driver */
    if (d1.available == 1) {
        t1.driverId = d1.id;
        t1.state = ASSIGNED;
        d1.available = 0;
        cout << "Driver Assigned. State: ASSIGNED" << endl;
    }

    /* Cancel Trip */
    if (t1.state == ASSIGNED || t1.state == REQUESTED) {
        t1.state = CANCELLED;
        d1.available = 1;   // driver free again
        cout << "Trip Cancelled. State: CANCELLED" << endl;
    }

    cout << "Driver Availability After Cancellation: " << d1.available << endl;

    return 0;
}
