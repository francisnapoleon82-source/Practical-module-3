#include <iostream>
#include <string>
using namespace std;

// PA0201: Parent class with base functionality
class Vehicle {
protected:
    string brand;
    int speed;
public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    virtual void drive() {
        cout << brand << " is driving at " << speed << " km/h" << endl;
    }
};

// Child classes with extended functionality (Inheritance)
class Car : public Vehicle {
private:
    int doors;
public:
    Car(string b, int s, int d) : Vehicle(b, s), doors(d) {}
    void drive() override { // PA0203: Polymorphism
        cout << brand << " car with " << doors << " doors drives at " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasCarrier;
public:
    Bike(string b, int s, bool c) : Vehicle(b, s), hasCarrier(c) {}
    void drive() override { // Polymorphism
        cout << brand << " bike drives at " << speed << " km/h";
        if (hasCarrier) cout << " with a carrier.";
        cout << endl;
    }
};

// PA0204: Aggregation (Has-A relationship)
class Driver {
private:
    string name;
    Vehicle* vehicle; // Driver has-a Vehicle
public:
    Driver(string n, Vehicle* v) : name(n), vehicle(v) {}
    void startJourney() {
        cout << name << " starts journey: ";
        vehicle->drive();
    }
};

/// @brief 
/// @return 
int main() {
    // PA0202: Encapsulation – data and methods bundled in objects
    Car myCar("Toyota", 120, 4);
    Bike myBike("BMX", 80, true);

    // Instantiate objects and demonstrate polymorphism
    myCar.drive();
    myBike.drive();

    // Aggregation: Driver has-a Vehicle
    Driver d1("Kagiso", &myCar);
    Driver d2("Napoleon", &myBike);

    d1.startJourney();
    d2.startJourney();

    return 0;
}
