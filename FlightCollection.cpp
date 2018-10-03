#include "FlightCollection.h"

FlightCollection::FlightCollection()
{
    size = 0;
}

void FlightCollection::addFlight(Flight f)
{
    flights.push_back(f);
    size++;
}

Flight* FlightCollection::getFlight(string id)
{
    for(int i = 0; i < size; i++)
    {
        if(flights.at(i).getFlightID() == id)
        {
            return &flights.at(i);
        }
    }
}

Flight* FlightCollection::getFlight(int i)
{
    return &flights.at(i);
}

void FlightCollection::deleteFlight(string id)
{
    for(int i = 0; i < size; i++)
    {
        if(flights.at(i).getFlightID() == id)
        {
            flights.erase(flights.begin() + i);
            size--;
        }
    }
}

void FlightCollection::printFlights()
{
    for(int i = 0; i < size; i++)
    {
        cout << "-- Flight " << (i + 1) << " --" << endl;
        flights.at(i).printInfo();
    }
}

int FlightCollection::getSize()
{
    return size;
}

// Determines if a flight with the given crew and plane is possible
bool FlightCollection::flightPossible(Plane* p, CrewMember* cm[], struct tm* st, struct tm* et)
{
    // Proper role assignment
    if(cm[0]->getRole() != "Pilot" && cm[1]->getRole() != "CoPilot" && cm[2]->getRole() != "Cabin" && cm[3]->getRole() != "Cabin" && cm[4]->getRole() != "Cabin")
    {
        return false;
    }

    // Check if endtime is before starttime
    if(difftime(mktime(et), mktime(st)) < 0)
    {
        return false;
    }
    
    for(int i = 0; i < p->getNumAssignments(); i++)
    {
        if(timeIntersection(getFlight(p->getAssignment(i)), et, st))
        {
            return false;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < cm[i]->getNumAssignments(); j++)
        {
            if(timeIntersection(getFlight(cm[i]->getAssignment(j)), et, st))
            {
                return false;
            }
        }

    }

    return true;
}

// Loops through flights and determines if the specified flight exist
bool FlightCollection::flightExists(string fid)
{
    bool e = false;
    for(int i = 0; i < size; i++)
    {
        if(flights.at(i).getFlightID() == fid)
        {
            e = true;
        }
    }
    return e;
}

// Checks if there is an intersection in time between the flight and the given start and end times
bool FlightCollection::timeIntersection(Flight* f, struct tm* et, struct tm* st)
{
    if(difftime(mktime(st), mktime(f->getStartP())) >= 0 && difftime(mktime(f->getEndP()), mktime(st)) >= 0)
    {
        return true;
    }

    if(difftime(mktime(f->getStartP()), mktime(st)) >= 0 && difftime(mktime(et), mktime(f->getStartP()) > 0))
    {
        return true;
    }
}