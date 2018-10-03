#import "Flight.h"
#include <time.h>

using namespace std;

// Default Constructor
Flight::Flight()
{
    time_t t;

    time(&t);

    starttime = *localtime(&t);
    endtime = *localtime(&t);
    flightid = "";
    startcode = "";
    endcode = "";
    status = "";
    numpassengers = 0;
}

Flight::Flight(string fid, Plane* pl, CrewMember* p, CrewMember* cp, CrewMember* c1, CrewMember* c2, CrewMember* c3, struct tm st, struct tm et, string sc, string ec, int np, string s)
{
    
    crew.push_back(p);
    crew.push_back(cp);
    crew.push_back(c1);
    crew.push_back(c2);
    crew.push_back(c3);

    plane = pl;

    starttime = st;
    endtime = et;
    flightid = fid;
    startcode = sc;
    endcode = ec;
    status = s;
    numpassengers = np;
}

void Flight::setCrew(CrewMember* c[])
{
    for(int i = 0; i < crew.size(); i++)
    {
        crew.push_back(c[i]);
    }
}

void Flight::setPlane(Plane* p)
{
    plane = p;
}

void Flight::setFlightID(string fid)
{
    flightid = fid;
}

string Flight::getFlightID()
{
    return flightid;
}

string Flight::getPilotID()
{
    for(int i = 0; i < 5; i++)
    {
        if(crew[i]->getRole() == "Pilot")
        {
            return crew[i]->getID();
        }
    }
}

string Flight::getCoPilotID()
{
    for(int i = 0; i < 5; i++)
    {
        if(crew[i]->getRole() == "CoPilot")
        {
            return crew[i]->getID();
        }
    }
}

string Flight::getCrewID(int i)
{
    return crew[i]->getID();
}

struct tm Flight::getStart()
{
    return starttime;
}

struct tm* Flight::getStartP()
{
    return &starttime;
}

string Flight::getPlaneTailNumber()
{
    return plane->getTailNumber();
}

void Flight::setStart(struct tm start)
{
    starttime = start;
}

struct tm Flight::getEnd()
{
    return endtime;
}

struct tm* Flight::getEndP()
{
    return &endtime;
}

void Flight::setEnd(struct tm end)
{
    endtime = end;
}

string Flight::getStartAirportCode()
{
    return startcode;
}

void Flight::setStartAirportCode(string c)
{
    startcode = c;
}

string Flight::getEndAirportCode()
{
    return endcode;
}

void Flight::setEndAirportCode(string c)
{
    endcode = c;
}

int Flight::getNumberOfPassengers()
{
    return numpassengers;
}

void Flight::addPassengers(int np)
{
    numpassengers += np;
}

void Flight::setPassengers(int np)
{
    numpassengers = np;
}

string Flight::getStatus()
{
    return status;
}

void Flight::setStatus(string s)
{
    status = s;
}

void Flight::printInfo()
{
    char time[20];


    cout << " !Flight ID: " << flightid << endl;
    cout << " !Plane Tail Number: " << getPlaneTailNumber() << endl;
    cout << " !Crew ID's: " << endl;
        for(int i = 0; i < 5; i++)
        {
            cout << "  *" << crew[i]->getRole() << ": " << getCrewID(i) << endl;
        }

    strftime(time, 20, "%D at %r", &starttime);
    cout << " !Start Time: " << time << endl;
    cout << " !Start Code: " << startcode << endl;

    strftime(time, 20, "%D at %r", &endtime);
    cout << " !End Time: " << time << endl;
    cout << " !End Code: " << endcode << endl;
    cout << " !Number of Passengers: " << numpassengers << endl;
    cout << " !Status: " << status << endl;
}