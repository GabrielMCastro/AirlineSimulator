#include "Cabin.h"

Cabin::Cabin()
{
    CrewMember::setName("");
    CrewMember::setID("");
    CrewMember::setStatus("");
    position = "";
}

Cabin::Cabin(string n, string id, string s, string p)
{
    CrewMember::setName(n);
    CrewMember::setID(id);
    CrewMember::setStatus(s);
    position = p;   
}

void Cabin::setPosition(string p)
{
    position = p;
}

string Cabin::getPosition()
{
    return position;
}

void Cabin::printInfo()
{
    CrewMember::printInfo();
    cout << " !Position: " << position << endl;
}