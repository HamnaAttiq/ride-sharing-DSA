#include <iostream>
#include <string>

using namespace std;

/* ---------- DRIVER ---------- */
class Driver {
public:
    int id;
    string location;
    bool available;

    Driver(int i, string loc) {
        id = i;
        location = loc;
        available = true;
    }
};

/* ---------- RIDER ---------- */
class Rider {
public:
    int id;
    string pickup;
    string drop;

    Rider(int i, string p, string d) {
        id = i;
        pickup = p;
        drop = d;
    }
};

/* ---------- TRIP ---------- */
class Trip {
public:
    int id;
    int riderId;
    int driverId;

    Trip(int t, int r) {
        id = t;
        riderId = r;
        driverId = -1;
    }
};

/* ---------- MAIN ---------- */
int main() {

    Driver d1(1, "Location A");
    Rider r1(101, "Location A", "Location B");
    Trip t1(1001, r1.id);

    cout << "Driver ID: " << d1.id << endl;
    cout << "Driver Location: " << d1.location << endl;

    cout << "Rider ID: " << r1.id << endl;
    cout << "Pickup: " << r1.pickup << endl;
    cout << "Drop: " << r1.drop << endl;

    cout << "Trip ID: " << t1.id << endl;
    cout << "Rider in Trip: " << t1.riderId << endl;
    cout << "Driver Assigned: " << t1.driverId << endl;

    return 0;
}
