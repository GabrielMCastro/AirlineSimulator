/* The .h definition file for FlightCollection.cpp
 */

#ifndef FLIGHTCOLLECTION_H
#define FLIGHTCOLLECTION_H

#include "Flight.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


class FlightCollection
{
    public:
        FlightCollection();
        void addFlight(Flight f);
        void deleteFlight(string id);
        void printFlights();
        bool flightPossible(Plane* p, CrewMember* cm[], struct tm* st, struct tm* et);
        bool flightExists(string fid);
        bool timeIntersection(Flight* f, struct tm* et, struct tm* st);
        Flight* getFlight(string id);
        Flight* getFlight(int index);
        int getSize();
    private:
        vector<Flight> flights;
        int size;
};

#endif