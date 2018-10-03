#include "CrewMemberCollection.h"
#include "CrewMember.h"
#include <string>
#include <iostream>

CrewMemberCollection::CrewMemberCollection()
{
    size = 0;
}

void CrewMemberCollection::addCrewMember(CrewMember* c)
{
    crew.push_back(c);
    size++;
}

CrewMember* CrewMemberCollection::getCrewMemberByName(string name)
{
    for(int i = 0; i < size; i++)
    {
        if(crew.at(i)->getName() == name)
        {
            return crew.at(i);
        }
    }
}

CrewMember* CrewMemberCollection::getCrewMemberByID(string id)
{
    for(int i = 0; i < size; i++)
    {
        if(crew.at(i)->getID() == id)
        {
            return crew.at(i);
        }
    }
}

CrewMember* CrewMemberCollection::getCrewMember(int i)
{
    return crew.at(i);
}


void CrewMemberCollection::deleteCrewMemberByName(string name)
{
    for(int i = 0; i < size; i++)
    {
        if(crew.at(i)->getName() == name)
        {
            crew.erase(crew.begin() + i);
            size--;
        }
    }
}

void CrewMemberCollection::deleteCrewMemberByID(string id)
{
    for(int i = 0; i < size; i++)
    {
        if(crew.at(i)->getID() == id)
        {
            crew.erase(crew.begin() + i);
            size--;
        }
    }
}

void CrewMemberCollection::printCrewMembers()
{
    for(int i = 0; i < size; i++)
    {
        cout << "-- Crew Member " << (i + 1) << " --" << endl;
        crew.at(i)->printInfo();
    }
}

int CrewMemberCollection::getSize()
{
    return size;
}


// Loops through the crew and checks if any have the given id
bool CrewMemberCollection::crewMemberExists(string id)
{
    bool e = false;
    for(int i = 0; i < size; i++)
    {
        if(crew.at(i)->getID() == id)
        {
            e = true;
        }
    }
    return e;
}