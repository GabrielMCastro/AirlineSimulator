#include "Plane.h"

// Default Constructor
Plane::Plane()
{
    make = "";
    model = "";
    status = "";
    tailnumber = "";
    seatnum = 0;
    range = 0;
}

// Secondary Constructor
Plane::Plane(string mk, string m, string st, string tn, int s, int r)
{
    make = mk;
    model = m;
    status = st;
    tailnumber = tn;
    seatnum = s;
    range = r;
}

string Plane::getMake()
{
    return make;
}

void Plane::setMake(string m)
{
    make = m;
}

string Plane::getModel()
{
    return model;
}

void Plane::setModel(string m)
{
    model = m;
}
    
string Plane::getStatus()
{
    return status;
}

void Plane::setStatus(string s)
{
    status = s;
}

string Plane::getTailNumber()
{
    return tailnumber;
}

void Plane::setTailNumber(string t)
{
    tailnumber = t;
}

int Plane::getNumberOfSeats()
{
    return seatnum;
}

void Plane::setNumberOfSeats(int s)
{
    seatnum = s;
}

int Plane::getRange()
{
    return range;
}

void Plane::setRange(int r)
{
    range = r;
}

string Plane::getAssignment(int i)
{
    return assignments.at(i);
}

void Plane::addAssignment(string id)
{
    assignments.push_back(id);
}

void Plane::printInfo()
{
    cout << " !Make: " << make << endl;
    cout << " !Model: " << model << endl;
    cout << " !Status: " << status << endl;
    cout << " !Tail Number: " << tailnumber << endl;
    cout << " !Number of Seats: " << seatnum << endl;
    cout << " !Range: " << range << endl;
}

int Plane::getNumAssignments()
{
    return assignments.size();
}