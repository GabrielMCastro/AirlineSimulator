#ifndef FLIGHT_H
#define FLIGHT_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "CrewMember.h"
#include "Plane.h"

using namespace std;

class Flight
{
    public:
        Flight();
        Flight(string fid, Plane* pl, CrewMember* p, CrewMember* cp, CrewMember* c1, CrewMember* c2, CrewMember* c3, struct tm st, struct tm et, string sc, string ec, int np, string s);
        void setCrew(CrewMember* c[]);
        void setPlane(Plane* p);
        void setStart(struct tm start);
        void setEnd(struct tm end);
        void setStartAirportCode(string c);
        void setEndAirportCode(string c);
        void setStatus(string s);
        void setFlightID(string fid);
        void addPassengers(int np);
        void setPassengers(int np);
        void printInfo();
        string getFlightID();
        string getPilotID();
        string getCoPilotID();
        string getCrewID(int i); // By index
        string getStartAirportCode();
        string getEndAirportCode();
        string getStatus();
        string getPlaneTailNumber();
        struct tm getStart();
        struct tm getEnd();
        struct tm* getStartP();
        struct tm* getEndP();
        int getNumberOfPassengers();
    private:
        vector<CrewMember*> crew;
        Plane* plane;
        struct tm starttime;
        struct tm endtime;
        string flightid;
        string startcode;
        string endcode;
        int numpassengers;
        string status; // Active, Cancelled, Completed
};

#endif