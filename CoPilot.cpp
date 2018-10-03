#include "CoPilot.h"

// Default constructor
CoPilot::CoPilot()
{
    CrewMember::setName("");
    CrewMember::setID("");
    CrewMember::setStatus("");
    rating = "";
    hours = 0;
}

// Secondary constructor
CoPilot::CoPilot(string n, string id, string s, string r, int h)
{
    CrewMember::setName(n);
    CrewMember::setID(id);
    CrewMember::setStatus(s);
    rating = r;
    hours = h;
}

void CoPilot::setRating(string r)
{
    rating = r;
}

void CoPilot::setHours(int h)
{
    hours = h;
}

void CoPilot::addHours(int h)
{
    hours += h;
}

string CoPilot::getRating()
{
    return rating;
}

int CoPilot::getHours()
{
    return hours;
}

// Prints the member info
void CoPilot::printInfo()
{
    CrewMember::printInfo();
    cout << " !Rating: " << rating << endl;
    cout << " !Total Hours: " << hours << endl;
}