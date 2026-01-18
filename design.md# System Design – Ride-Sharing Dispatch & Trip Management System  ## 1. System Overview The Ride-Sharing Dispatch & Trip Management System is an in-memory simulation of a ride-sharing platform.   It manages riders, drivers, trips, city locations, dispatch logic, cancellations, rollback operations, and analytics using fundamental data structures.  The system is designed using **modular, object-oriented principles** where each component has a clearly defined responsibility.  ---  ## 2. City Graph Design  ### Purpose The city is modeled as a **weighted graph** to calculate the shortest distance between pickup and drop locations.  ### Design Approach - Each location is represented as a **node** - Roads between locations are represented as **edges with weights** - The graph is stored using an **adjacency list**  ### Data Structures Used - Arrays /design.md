# System Design – Ride-Sharing Dispatch & Trip Management System

## 1. System Overview
The Ride-Sharing Dispatch & Trip Management System is an in-memory simulation of a ride-sharing platform.  
It manages riders, drivers, trips, city locations, dispatch logic, cancellations, rollback operations, and analytics using fundamental data structures.

The system is designed using **modular, object-oriented principles** where each component has a clearly defined responsibility.

---

## 2. City Graph Design

### Purpose
The city is modeled as a **weighted graph** to calculate the shortest distance between pickup and drop locations.

### Design Approach
- Each location is represented as a **node**
- Roads between locations are represented as **edges with weights**
- The graph is stored using an **adjacency list**

### Data Structures Used
- Arrays / Linked Lists for adjacency list
- Simple shortest path algorithm (Dijkstra or BFS)

### Key Operations
- Add location
- Add road between locations
- Compute shortest path distance

---

## 3. Driver and Rider Design

### Driver
Each driver contains:
- Driver ID
- Current location
- Availability status (available / busy)
- Zone

### Rider
Each rider contains:
- Rider ID
- Pickup location
- Drop location

Drivers and riders are stored using simple arrays or lists.

---

## 4. Trip Lifecycle and State Machine

### Trip Entity
A trip represents a ride request and contains:
- Trip ID
- Rider ID
- Driver ID
- Distance
- Trip State

### Trip States
The trip lifecycle follows a strict state machine:

### State Validation
Invalid state transitions are not allowed.  
Each state change is validated before being applied.

---

## 5. Dispatch Engine Design

### Purpose
The Dispatch Engine assigns an available driver to a rider request.

### Allocation Strategy
1. Search for an available driver in the same zone
2. If no driver is available, search in other zones
3. Select the nearest available driver
4. Calculate trip distance using the city graph

### Output
- Assigned driver ID
- Updated trip state
- Calculated distance

---

## 6. Rollback Mechanism

### Purpose
The rollback mechanism ensures system consistency when a trip is cancelled or an error occurs.

### Design Approach
- A **stack** is used to store actions performed during trip assignment
- Each allocation or state change is pushed onto the stack
- On rollback, the last action is popped and reversed

### Operations Supported
- Rollback last trip assignment
- Rollback multiple actions

---

## 7. Analytics and Reporting

### Purpose
Analytics provide insights into system usage and performance.

### Metrics Tracked
- Total trips completed
- Total trips cancelled
- Average trip distance
- Driver utilization

### Data Storage
Completed and cancelled trips are stored in history lists for analysis.

---

## 8. System Controller Design

### RideShareSystem
This class acts as the central controller and coordinates all components:
- Manages drivers, riders, and trips
- Invokes dispatch engine
- Handles rollback operations
- Generates analytics

---

## 9. Error Handling and Validation

### Validations
- Prevent invalid state transitions
- Prevent assigning busy drivers
- Prevent rollback when no actions exist

### Error Handling Strategy
- Graceful error messages
- System state remains consistent after failures

---

## 10. Complexity Analysis (High-Level)

| Operation | Complexity |
|---------|------------|
| Driver Search | O(n) |
| Shortest Path | O(E log V) |
| Rollback | O(1) |
| Analytics | O(n) |

---

## 11. Conclusion
The system design emphasizes clarity, modularity, and correctness.  
By combining data structures such as graphs and stacks with state machine logic, the project demonstrates a practical application of core data structure concepts in a real-world-inspired system.


