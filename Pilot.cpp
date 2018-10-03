#include "Pilot.h"

// Default constructor
Pilot::Pilot()
{
    CrewMember::setName("");
    CrewMember::setID("");
    CrewMember::setStatus("");
    rating = "";
    hours = 0;
}

// Secondary constructor
Pilot::Pilot(string n, string id, string s, string r, int h)
{
    CrewMember::setName(n);
    CrewMember::setID(id);
    CrewMember::setStatus(s);
    rating = r;
    hours = h;
}

void Pilot::setRating(string r)
{
    rating = r;
}

void Pilot::setHours(int h)
{
    hours = h;
}

void Pilot::addHours(int h)
{
    hours += h;
}

string Pilot::getRating()
{
    return rating;
}

int Pilot::getHours()
{
    return hours;
}

// Prints the member info
void Pilot::printInfo()
{
    CrewMember::printInfo();
    cout << " !Rating: " << rating << endl;
    cout << " !Total Hours: " << hours << endl;
}