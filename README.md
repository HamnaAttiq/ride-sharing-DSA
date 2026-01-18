# Ride-Sharing Dispatch & Trip Management System

## 📌 Project Overview
This project is a simulation of a **Ride-Sharing Dispatch and Trip Management System**, similar to platforms like Uber or Careem, developed using **C++ and Data Structures**.  
The system runs entirely **in memory** and focuses on applying core data structure concepts rather than real-world APIs or maps.

The project manages riders, drivers, trips, city locations, dispatch logic, cancellations, rollbacks, and analytics.

---

## 🎯 Objectives
- Simulate ride request and driver dispatch process
- Implement a **trip lifecycle state machine**
- Assign drivers using **shortest path logic**
- Handle trip cancellation with **rollback mechanism**
- Maintain trip history and generate analytics
- Apply data structures in a real-world scenario

---

## 🧩 System Features

### 🚕 Driver & Rider Management
- Register drivers with availability status
- Register riders with pickup and drop locations

### 🗺️ City Representation
- City modeled as a **weighted graph**
- Locations connected with distances
- Shortest path used to calculate trip distance

### 🔄 Trip Lifecycle Management
Each trip follows a strict lifecycle:

