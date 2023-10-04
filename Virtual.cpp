#include <iostream>
using namespace std;

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

    // what does virtual keyword do in this code? what changes do they bring in the compiler? why do we need a virtual function?
    // -> pointer of an obj of class Vehicle will priortize the member function of the base class Vehicle itself
    //    and will by-pass the member function in the derived class, i.e, class Bike.
    //    hence to overload the member function of the base class that is also present in the derived class,
    //    and to make a runtime polymorphism of the code, virtual keyword is used in front of the functions.
    //    without the 'virtual' keyword, the printDetails() present in the derived class will be overlooked in compile time polymorphism.
    //    a virtual member function should be redefined in the derived class, otherwise it will not be overloaded.

    // void printDetails()
    virtual void printDetails()
    {
        /*
         */
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
    // Unlike abstract class, in a non abstract class, objects of base class can be created.
    // In this code, base class Vehicle has no pure virtual member function(only has a un-pure virtual member function), hence its not a abstract class.

    Vehicle v1(160, 2);
    cout << endl << "details of obj of Vehicle class: " << endl;
    v1.printDetails();

    Bike b1("Apache", 180, 2);
    cout << endl << "details of obj of Bike class class (without pointer): " << endl;
    b1.printDetails();

    Vehicle *vptr = &b1;
    
    // in this pointer initialization, the Vehicle class's member function will be invoked and will be used,
    // but by using the virtual keyword in the base class before member function printDetails(),
    // the compiler overlooks Vehicle class member function and is overridden by its derived class member function named the same, i.e, printDetails().


    cout << endl << "details of obj of Bike class class (WITH pointer): " << endl;
    vptr->printDetails();

    return 0;
}