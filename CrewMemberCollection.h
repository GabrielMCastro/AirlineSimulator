#ifndef CREWMEMBERCOLLECTION_H
#define CREWMEMBERCOLLECTION_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "CrewMember.h"

using namespace std;


class CrewMemberCollection 
{
    public:
        CrewMemberCollection();
        void addCrewMember(CrewMember* c);
        CrewMember* getCrewMemberByName(string n);
        CrewMember* getCrewMemberByID(string id);
        CrewMember* getCrewMember(int i);
        void deleteCrewMemberByName(string n);
        void deleteCrewMemberByID(string id);
        void printCrewMembers();
        int getSize();
        bool crewMemberExists(string id);
    private:
        vector<CrewMember*> crew;
        int size;
};

#endif