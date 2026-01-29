#include <iostream>
using namespace std;

/* Trip States */
#define REQUESTED 0
#define ASSIGNED 1
#define CANCELLED 2

/* Simple STACK (array based) */
int stack[10];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    int value = stack[top];
    top--;
    return value;
}

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

/* Trip */
class Trip {
public:
    int id;
    int driverId;
    int state;

    Trip(int t) {
        id = t;
        driverId = -1;
        state = REQUESTED;
    }
};

int main() {

    Driver d1(1);
    Trip t1(1001);

    cout << "Trip Created. State: REQUESTED" << endl;

    /* Assign Driver */
    if (d1.available == 1) {
        t1.driverId = d1.id;
        t1.state = ASSIGNED;
        d1.available = 0;

        push(ASSIGNED);   // save action in stack
        cout << "Driver Assigned. State: ASSIGNED" << endl;
    }

    /* Cancel Trip */
    if (t1.state == ASSIGNED) {
        t1.state = CANCELLED;
        push(CANCELLED);  // save cancel action
        cout << "Trip Cancelled. State: CANCELLED" << endl;
    }

    /* ROLLBACK */
    cout << "Performing Rollback..." << endl;

    int lastAction = pop();

    if (lastAction == CANCELLED) {
        t1.state = ASSIGNED;
        cout << "Rollback: Trip back to ASSIGNED" << endl;
    }

    lastAction = pop();

    if (lastAction == ASSIGNED) {
        t1.driverId = -1;
        d1.available = 1;
        t1.state = REQUESTED;
        cout << "Rollback: Driver unassigned, Trip back to REQUESTED" << endl;
    }

    cout << "Driver Availability After Rollback: " << d1.available << endl;

    return 0;
}
