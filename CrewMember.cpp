#include "CrewMember.h"

// Default constructor
CrewMember::CrewMember()
{
    name = "";
    crewid = "";
    status = "";
}

// Second constructor
CrewMember::CrewMember(string n, string id, string s)
{
    name = n;
    crewid = id;
    status = s;
}

void CrewMember::setName(string n)
{
    name = n;
}

void CrewMember::setID(string id)
{
    crewid = id;
}

void CrewMember::setStatus(string s)
{
    status = s;
}

// Adds an assigment
void CrewMember::addAssignment(string id)
{
    assignments.push_back(id);
}

// Prints the member info
void CrewMember::printInfo()
{
    cout << " !Role: " << role << endl;
    cout << " !Name: " << name << endl;
    cout << " !Crew ID: " << crewid << endl;
    cout << " !Status: " << status << endl;
}

string CrewMember::getName()
{
    return name;
}

string CrewMember::getID()
{
    return crewid;
}

string CrewMember::getStatus()
{
    return status;
}

string CrewMember::getAssignment(int i)
{
    return assignments.at(i);
}

string CrewMember::getAssignment(struct tm t) // Given Time
{
    // To Fill
}

void CrewMember::setRole(string r)
{
    role = r;
}

string CrewMember::getRole()
{
    return role;
}

int CrewMember::getNumAssignments()
{
    return assignments.size();
}