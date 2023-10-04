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
    // ans: A class having at least one Pure virtual function makes it an abstract class, this class cant create objects of its own becuz it has an 
    // ->   incomplete structure, in other words, this class has a member function with doesn't have a definition,
    // ->   i.e, the member function initialized as '0'.
    // ->   in this case, class Vehicle has one member function with pure virtual member function, other member functions arent virtual or pure virtual.
    // ->   hence this base class, class Vehicle, is an abstract class.
    // ->   and becuz the derived class is not abstract like class car, its not abstract cuz we overloaded the pure virtual function in the derived class
    // ->   by defining its own member function with same name in derived class, its called function overriding. (run time polymorphism)
  
    // NOTE: abstract class will create its own default constructor if none are provided.

    virtual void Virtual_useless()
    {
        cout << "doesnt do anything !!!";
    }

    void NotVirtual_ButUseless()
    {
        cout << "doesnt do anything !!!";
    }


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
    // below line will throw an error cuz class Vehicle is an abstract class and abstract class cant have its own objects,
    // but can have objects of its derived class by overriding the base class member function.

    // Vehicle v1(200 , 3);

    Bike b1("Apache", 180, 2);
    Car c1("Skoda", 1500, 4);

    b1.printDetails();
    cout << endl;
    c1.printDetails();

    return 0;
}