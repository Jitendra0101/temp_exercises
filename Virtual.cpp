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


    // what does virtual keyword do in this code. what changes do they bring in the compiler.


    // void printDetails()
    virtual void printDetails()
    {
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
    Vehicle v1(160, 2);

    Bike b1("Apache", 180, 2);
    // b1.printDetails();

    Vehicle *vptr = &b1;

    vptr->printDetails();

    return 0;
}