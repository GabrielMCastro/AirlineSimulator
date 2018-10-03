#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <vector>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

class CrewMember
{
    public:
        CrewMember();
        CrewMember(string n, string id, string s);
        void setName(string n);
        void setID(string id);
        void setStatus(string s);
        void addAssignment(string id);
        virtual void printInfo();
        void setRole(string r);
        string getName();
        string getID();
        string getStatus();
        string getAssignment(int i);
        string getAssignment(struct tm t); // Given Time
        string getRole();
        int getNumAssignments();
    protected:
        string name;
        string crewid;
        string status;
        string role; // Pilot, CoPilot, Cabin
        vector<string> assignments;
};
#endif