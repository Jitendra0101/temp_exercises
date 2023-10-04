#include <iostream>
using namespace std;

// ABSTRACT CLASS
// which contains at least one pure virtual function
// can not have any objects

// Pure virtual function
// doesn't have a body, no defination.

class Vehicle
{
protected:
    int cc;
    int tyres;

public:
    Vehicle() {}

    Vehicle(int cc, int tyres)
    {
        this->cc = cc;
        this->tyres = tyres;
    }

    // why cant a abstract class have objects of its own but can have objects of its derived classes?
    // ans:  
    // -> becuz the derived class is not abstract like class car, its not abstract cuz we overloaded the pure virtual function in the derived class.


    virtual void printDetails() = 0;
};

class Car : public Vehicle
{
    string model;

public:
    Car() {}

    Car(string model, int cc, int tyres) : Vehicle(cc, tyres)
    {
        this->model = model;
    }

    void printDetails()
    {
        cout << "Model:" << model << endl;
        cout << "CC: " << cc << endl;
        cout << "Tyres: " << tyres << endl;
    }
};

class Bike : public Vehicle
{
    string model;

public:
    Bike() {}

    Bike(string model, int cc, int tyres) : Vehicle(cc, tyres)
    {
        this->model = model;
    }

    void printDetails()
    {
        cout << "Model:" << model << endl;
        cout << "CC: " << cc << endl;
        cout << "Tyres: " << tyres << endl;
    }
};

int main()
{

    // Vehicle v1(200 , 3);

    Bike b1("Apache", 180, 2);
    Car c1("Skoda", 1500 , 4);

    b1.printDetails();
    cout << endl;
    c1.printDetails();

    return 0;
}