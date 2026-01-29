#include <iostream>
using namespace std;

/* Trip States */
#define COMPLETED 1
#define CANCELLED 2

/* Trip */
class Trip {
public:
    int id;
    int state;

    Trip(int t, int s) {
        id = t;
        state = s;
    }
};

int main() {

    /* Sample Trips (history) */
    Trip t1(1001, COMPLETED);
    Trip t2(1002, CANCELLED);
    Trip t3(1003, COMPLETED);
    Trip t4(1004, COMPLETED);
    Trip t5(1005, CANCELLED);

    int totalTrips = 5;
    int completedTrips = 0;
    int cancelledTrips = 0;

    /* Count analytics */
    if (t1.state == COMPLETED) completedTrips++;
    if (t1.state == CANCELLED) cancelledTrips++;

    if (t2.state == COMPLETED) completedTrips++;
    if (t2.state == CANCELLED) cancelledTrips++;

    if (t3.state == COMPLETED) completedTrips++;
    if (t3.state == CANCELLED) cancelledTrips++;

    if (t4.state == COMPLETED) completedTrips++;
    if (t4.state == CANCELLED) cancelledTrips++;

    if (t5.state == COMPLETED) completedTrips++;
    if (t5.state == CANCELLED) cancelledTrips++;

    /* Print Analytics */
    cout << "===== ANALYTICS REPORT =====" << endl;
    cout << "Total Trips: " << totalTrips << endl;
    cout << "Completed Trips: " << completedTrips << endl;
    cout << "Cancelled Trips: " << cancelledTrips << endl;

    int completionRate = (completedTrips * 100) / totalTrips;
    cout << "Completion Rate: " << completionRate << "%" << endl;

    return 0;
}
