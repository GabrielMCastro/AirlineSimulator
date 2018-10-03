/* This program maintains and schedules flights for the Mean Green airlines.
 *
 * Homework 5
 * gmc0094 
 * Gabriel Castro
 * GabrielCastro@my.unt.edu
 */

#include <iostream>
#include "Plane.h"
#include "PlaneCollection.h"
#include "Pilot.h"
#include "CoPilot.h"
#include "Cabin.h"
#include "CrewMember.h"
#include "CrewMemberCollection.h"
#include "Flight.h"
#include "FlightCollection.h"

using namespace std;

// Functions
void loadData();
void saveData();
void printTopMenu();
void printPlaneMenu();
void printFlightMenu();
void printCrewMenu();
// Crew Functions
void addCrewMember();
void editCrewMember();
void deleteCrewMember();
void printCrewMember();
// Plane Functions
void addPlane();
void editPlane();
void deletePlane();
void printPlane();
// Flight Functions
void addFlight();
void addPassengers();
void editFlight();
void deleteFlight();
void deleteFlightByStatus();
void printFlight();

// Variables
bool quit = false;
string buffer = ""; // used to clear the cin buffer
// Collections
PlaneCollection planes;
CrewMemberCollection crew;
FlightCollection flights;

int main()
{
    // loadData();
    
    while(!quit)
    {
        printTopMenu();
    }

    //  saveData();
}


// Prints the top layer of the menu
void printTopMenu()
{
    string input;

    cout << "---------------------------------" << endl;
    cout << "TOP MENU" << endl;
    cout << " * Crew Menu: c" << endl;
    cout << " * Plane Menu: p" << endl;
    cout << " * Flight Menu: f" << endl;
    cout << " * Quit: q" << endl;

    bool in = true;

    do
    {
        cout << "Enter valid input: "; cin >> input;

        if(input == "c")
        {
            printCrewMenu();
            in = false;
        }else if(input == "p")
        {
            printPlaneMenu();
            in = false;
        }else if(input == "f")
        {
            printFlightMenu();
            in = false;
        }else if(input == "q")
        {
            in = false;
            quit = true;
        }
    }
    while(in);
}


// Prints Crew Member layer of the menu
void printCrewMenu()
{
    string input;

    cout << "---------------------------------" << endl;
    cout << "CREW MENU" << endl;
    cout << " * Top Menu: t" << endl;
    cout << " * Add: a" << endl;
    cout << " * Edit: e" << endl;
    cout << " * Delete: d" << endl;
    cout << " * Print One: p" << endl;
    cout << " * Print All: pa" << endl;
    cout << " * Print Menu: pm" << endl;
    cout << " * Quit: q" << endl;

    bool in = true;

    do
    {
        cout << "Enter valid input: "; cin >> input;

        if(input == "t")
        {
            in = false;
        }else if(input == "a") // Add
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Add Crew -" << endl;
            addCrewMember();
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
        }else if(input == "e") //  Edit
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Edit Crew -" << endl;
            editCrewMember();
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
        }else if(input == "d") // Delete
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Delete Crew -" << endl;
            deleteCrewMember();
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
        }else if(input == "p") // Print one
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Print Crew Info -" << endl;
            printCrewMember();
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
        }else if(input == "pa") // Print all
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- All Crew Info -" << endl;
            crew.printCrewMembers();
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
        }else if(input == "pm")
        {
            cout << "---------------------------------" << endl;
            cout << "CREW MENU" << endl;
            cout << " * Top Menu: t" << endl;
            cout << " * Add: a" << endl;
            cout << " * Edit: e" << endl;
            cout << " * Delete: d" << endl;
            cout << " * Print One: p" << endl;
            cout << " * Print All: pa" << endl;
            cout << " * Print Menu: pm" << endl;
            cout << " * Quit: q" << endl;
        }else if(input == "q") // Quit
        {
            in = false;
            quit = true;
        }
    }
    while(in);   
}

// Prints Plane layer of the menu
void printPlaneMenu()
{
    string input;
    
    cout << "---------------------------------" << endl;
    cout << "PLANE MENU" << endl;
    cout << " * Top Menu: t" << endl;
    cout << " * Add: a" << endl;
    cout << " * Edit: e" << endl;
    cout << " * Delete: d" << endl;
    cout << " * Print One: p" << endl;
    cout << " * Print All: pa" << endl;
    cout << " * Print Menu: pm" << endl;
    cout << " * Quit: q" << endl;

    bool in = true;

    do
    {
        cout << "Enter valid input: "; cin >> input;

        if(input == "t")
        {
            in = false;
        }else if(input == "a") // Add
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Add Plane -" << endl;
            addPlane();
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
        }else if(input == "e") //  Edit
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Edit Plane -" << endl;
            editPlane();
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
        }else if(input == "d") // Delete
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Delete Plane -" << endl;
            deletePlane();
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
        }else if(input == "p") // Print one
        {    
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Print Plane Info -" << endl;
            printPlane();
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
        }else if(input == "pa") // Print all
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- All Plane Info -" << endl;
            planes.printPlanes();
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
        }else if(input == "pm")
        {
            cout << "---------------------------------" << endl;
            cout << "PLANE MENU" << endl;
            cout << " * Top Menu: t" << endl;
            cout << " * Add: a" << endl;
            cout << " * Edit: e" << endl;
            cout << " * Delete: d" << endl;
            cout << " * Print One: p" << endl;
            cout << " * Print All: pa" << endl;
            cout << " * Print Menu: pm" << endl;
            cout << " * Quit: q" << endl;
        }else if(input == "q") // Quit
        {
            in = false;
            quit = true;
        }
    }
    while(in);   
}


// Prints Flight layer of the menu
void printFlightMenu()
{
    string input;

    cout << "---------------------------------" << endl;
    cout << "FLIGHT MENU" << endl;
    cout << " * Top Menu: t" << endl;
    cout << " * Add: a" << endl;
    cout << " * Edit: e" << endl;
    cout << " * Delete: d" << endl;
    cout << " * Delete by Status: ds" << endl;
    cout << " * Add Passengers: ap" << endl;
    cout << " * Print One: p" << endl;
    cout << " * Print All: pa" << endl;
    cout << " * Print Menu: pm" << endl;
    cout << " * Quit: q" << endl;

    bool in = true;

    do
    {
        cout << "Enter valid input: "; cin >> input;

        if(input == "t")
        {
            in = false;
        }else if(input == "a") // Add
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Add Flight -" << endl;
            addFlight();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "e") //  Edit
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Edit Flight -" << endl;
            editFlight();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "d") // Delete
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Delete Flight -" << endl;
            deleteFlight();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "ds") // Delete by status
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Delete Flight By Status -" << endl;
            deleteFlightByStatus();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "ap")
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Add Passengers to Flight -" << endl;
            addPassengers();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "p") // Print one
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- Print Flight Info -" << endl;
            printFlight();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "pa") // Print all
        {
            getline(cin, buffer); // clearing buffer
            cout << "---------------------------------" << endl;
            cout << "- All Flight Info -" << endl;
            flights.printFlights();
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
        }else if(input == "pm")
        {
            cout << "---------------------------------" << endl;
            cout << "FLIGHT MENU" << endl;
            cout << " * Top Menu: t" << endl;
            cout << " * Add: a" << endl;
            cout << " * Edit: e" << endl;
            cout << " * Delete: d" << endl;
            cout << " * Delete by Status: ds" << endl;
            cout << " * Add Passengers: ap" << endl;
            cout << " * Print One: p" << endl;
            cout << " * Print All: pa" << endl;
            cout << " * Print Menu: pm" << endl;
            cout << " * Quit: q" << endl;
        }else if(input == "q") // Quit
        {
            in = false;
            quit = true;
        }
    }
    while(in);  
}

// Adds a plane
void addPlane()
{
    string mk, m, st, tn;
    int s, r;

    cout << "Enter Plane Make: "; // Make
    getline(cin, mk);

    cout << "Enter Plane Model: "; // Model
    getline(cin, m);

    cout << "Enter Plane Tail Number: "; // Tail Number
    getline(cin, tn);

    cout << "Enter Number of Seats on Plane: "; // # Seats
    cin >> s;

    cout << "Enter Plane's Range (in miles): "; // Range
    cin >> r;

    getline(cin, buffer); // clearing buffer

    cout << "Enter Plane Status (Out, In, Repair): "; // Status
    getline(cin, st);
    
    while((st != "Out") && (st != "In") && (st != "Repair"))
    {
        cout << "Enter valid input: ";
        getline(cin, st);
    }

    Plane p(mk, m, st, tn, s, r);

    planes.addPlane(p);
}

// Edits an existing plane
void editPlane()
{
    string mk, m, st, otn, tn;
    int s, r;

    cout << "Enter Tail Number of Plane to edit: ";
    getline(cin, otn);

    while(!planes.planeExists(otn))
    {
        cout << "Plane with given tail number doesn't exits.\nEnter valid Tail Number: ";
        getline(cin, otn);
    }

    cout << "Current Info for " << otn << ": " << endl; // Printing old values
    planes.getPlane(otn)->printInfo();

    cout << "Enter updated Make: "; // Make
    getline(cin, mk);

    cout << "Enter updated Model: "; // Model
    getline(cin, m);

    cout << "Enter updated Tail Number: "; // Tail Number
    getline(cin, tn);

    cout << "Enter updated Seat Number: "; // # Seats
    cin >> s;

    cout << "Enter updated Range: "; // Range
    cin >> r;

    getline(cin, buffer); // clearing buffer

    cout << "Enter updated Status (Out, In, Repair): "; // Status
    getline(cin, st);
    
    while((st != "Out") && (st != "In") && (st != "Repair"))
    {
        cout << "Enter valid input: ";
        getline(cin, st);
    }


    Plane p(mk, m, st, tn, s, r);

    planes.deletePlane(otn); // Deleting old version of plane
    planes.addPlane(p); // Adding new version of plane;
}

// Deletes the specified plane
void deletePlane()
{
    string tn;

    cout << "Enter Tail Number of Plane to delete: ";
    getline(cin, tn);

    while(!planes.planeExists(tn))
    {
        cout << "Plane with given tail number doesn't exits.\nEnter valid Tail Number: ";
        getline(cin, tn);
    }

    planes.deletePlane(tn); // Deleting the plane
}

// Prints the specified plane
void printPlane()
{
    string tn;

    cout << "Enter Tail Number of Plane to print: ";
    getline(cin, tn);

    while(!planes.planeExists(tn))
    {
        cout << "Plane with given tail number doesn't exits.\nEnter valid Tail Number: ";
        getline(cin, tn);
    }

    planes.getPlane(tn)->printInfo(); // Prints the info for the plane
}

// Adds a crew member
void addCrewMember()
{
    string n, id, s, ro, r, p;
    int h;

    cout << "Enter Crew Member Name: "; // Name
    getline(cin, n);

    cout << "Enter Crew Member ID: "; // ID
    getline(cin, id);

    cout << "Enter Crew Member Status (Available, Sick, On Leave): "; // Status
    getline(cin, s);  
    while((s != "Available") && (s != "Sick") && (s != "On Leave"))
    {
        cout << "Enter valid input: ";
        getline(cin, s);
    }

    cout << "Enter Crew Member Role (Pilot, CoPilot, Cabin): "; // Crew Role
    getline(cin, ro);
    while((ro != "Pilot") && (ro != "CoPilot") && (ro != "Cabin"))
    {
        cout << "Enter valid input: ";
        getline(cin, ro);
    }

    if(ro == "Pilot") // Pilot
    {
        cout << "Enter Pilot Rating (A,B,C,D,F): ";
        getline(cin, r);
        while((r != "A") && (r != "B") && (r != "C") && (r != "D") && (r != "F"))
        {
            cout << "Enter valid input: ";
            getline(cin, r);
        }

        cout << "Enter the amount of hours the Pilot has: ";
        cin >> h;
        
        getline(cin, buffer); // clearing buffer

        Pilot* c = new Pilot(n, id, s, r, h);
        c->setRole(ro);
        crew.addCrewMember(c);
    }else if(ro == "CoPilot") // CoPilot
    {
        cout << "Enter CoPilot Rating (A,B,C,D): ";
        getline(cin, r);
        while((r != "A") && (r != "B") && (r != "C") && (r != "D"))
        {
            cout << "Enter valid input: ";
            getline(cin, r);
        }

        cout << "Enter the amount of hours the CoPilot has: ";
        cin >> h;

        getline(cin, buffer); // clearing buffer

        CoPilot* c = new CoPilot(n, id, s, r, h);
        c->setRole(ro);
        crew.addCrewMember(c);
    }else if(ro == "Cabin") // Cabin
    {
        cout << "Enter Cabin Member Position (FirstClass, BusinessClass EconomyFront, EconomyRear, Lead): ";
        getline(cin, p);
        while((p != "FirstClass") && (p != "BusinessClass") && (p != "EconomyFront") && (p != "EconomyRear") && (p != "Lead"))
        {
            cout << "Enter valid input: ";
            getline(cin, p);
        }

        Cabin* c = new Cabin(n, id, s, p);
        c->setRole(ro);
        crew.addCrewMember(c);
    }
}

// Edits an existing crew member
void editCrewMember()
{
    string n, oid, id, s, ro, r, p;
    int h;

    cout << "Enter ID of Crew Member to edit: ";
    getline(cin, oid);

    while(!crew.crewMemberExists(oid))
    {
        cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, oid);
    }

    cout << "Current Info for " << oid << ": " << endl; // Printing old values
    crew.getCrewMemberByID(oid)->printInfo();

    cout << "Enter updated Name: "; // Name
    getline(cin, n);

    cout << "Enter updated Status (Available, Sick, On Leave): "; // Status
    getline(cin, s);
    while((s != "Available") && (s != "Sick") && (s != "On Leave"))
    {
        cout << "Enter valid input: ";
        getline(cin, s);
    }

    cout << "Enter updated ID: "; // ID
    getline(cin, id);

    ro = crew.getCrewMemberByID(oid)->getRole();

    if(ro == "Pilot")
    {
        cout << "Enter Updated Pilot Rating (A,B,C,D,F): ";
        getline(cin, r);
        while((r != "A") && (r != "B") && (r != "C") && (r != "D") && (r != "F"))
        {
            cout << "Enter valid input: ";
            getline(cin, r);
        }

        cout << "Enter the updated amount of hours the Pilot has: ";
        cin >> h;

        getline(cin, buffer); // clearing buffer

        Pilot* c = new Pilot(n, id, s, r, h);
        c->setRole(ro);

        crew.deleteCrewMemberByID(oid); // Deleting the old version
        crew.addCrewMember(c); // Adding the new version
    }else if(ro == "CoPilot")
    {
        cout << "Enter Updated CoPilot Rating (A,B,C,D): ";
        getline(cin, r);
        while((r != "A") && (r != "B") && (r != "C") && (r != "D"))
        {
            cout << "Enter valid input: ";
            getline(cin, r);
        }

        cout << "Enter the updated amount of hours the CoPilot has: ";
        cin >> h;

        getline(cin, buffer); // clearing buffer

        CoPilot* c = new CoPilot(n, id, s, r, h);
        c->setRole(ro);

        crew.deleteCrewMemberByID(oid); // Deleting the old version
        crew.addCrewMember(c); // Adding the new version
    }else if(ro == "Cabin")
    {
        cout << "Enter the Updated Cabin Member Position (FirstClass, BusinessClass EconomyFront, EconomyRear, Lead): ";
        getline(cin, p);
        while((p != "FirstClass") && (p != "BusinessClass") && (p != "EconomyFront") && (p != "EconomyRear") && (p != "Lead"))
        {
            cout << "Enter valid input: ";
            getline(cin, p);
        }

        Cabin* c = new Cabin(n, id, s, p);
        c->setRole(ro);
        crew.deleteCrewMemberByID(oid); // Deleting the old version
        crew.addCrewMember(c); // Adding the new version
    }
}

// Deletes an existing crew member
void deleteCrewMember()
{
    string id;

    cout << "Enter ID of the Crew Member to delete: ";
    getline(cin, id);

    while(!crew.crewMemberExists(id))
    {
        cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, id);
    }

    crew.deleteCrewMemberByID(id); // Deleting the crew member
}

// Prints the info for a specified crew member
void printCrewMember()
{
    string id;

    cout << "Enter ID of the Crew Member to print: ";
    getline(cin, id);

    while(!crew.crewMemberExists(id))
    {
        cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, id);
    }

    crew.getCrewMemberByID(id)->printInfo(); // Printing crew member info
}

// Adds a flight
void addFlight()
{
    string fid, sc, ec, s, tn;
    string pid, cpid, c1id, c2id, c3id;
    int np, mp;
    struct tm st, et;
    CrewMember* c[5];

    cout << "Enter Flight ID: "; // ID
    getline(cin, fid);

    // Crew
    {
        cout << "Enter Crew ID for Pilot: "; // Pilot
        getline(cin, pid);
        while(!crew.crewMemberExists(pid))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, pid);
        }
        c[0] = crew.getCrewMemberByID(pid);
                
        cout << "Enter Crew ID for CoPilot: "; // CoPilot
        getline(cin, cpid);
        while(!crew.crewMemberExists(cpid))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, cpid);
        }
        c[1] = crew.getCrewMemberByID(cpid);

        cout << "Enter Crew ID for Cabin 1: "; // Cabin 1
        getline(cin, c1id);
        while(!crew.crewMemberExists(c1id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c1id);
        }
        c[2] = crew.getCrewMemberByID(c1id);

        cout << "Enter Crew ID for Cabin 2: "; // Cabin 2
        getline(cin, c2id);
        while(!crew.crewMemberExists(c2id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c2id);
        }
        c[3] = crew.getCrewMemberByID(c2id);

        cout << "Enter Crew ID for Cabin 3: "; // Cabin 3
        getline(cin, c3id);
        while(!crew.crewMemberExists(c3id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c3id);
        }
        c[4] = crew.getCrewMemberByID(c3id);
    }

    // Plane
    cout << "Enter Tail Number for Plane: ";
    getline(cin, tn);
    while(!planes.planeExists(tn))
    {
        cout << "Plane with given tail number doesn't exits.\nEnter valid Tail Number: ";
        getline(cin, tn);
    }
    mp = planes.getPlane(tn)->getNumberOfSeats();

    // Getting start and end time
    for(int i = 0; i < 2; i++)
    {
        string lab = "Starting";
        int m,h,d,mm,y;
        if(i == 1) { lab = "Ending";}

        cout << "Enter " << lab << " Time" << endl;

        cout << " -Enter Flight " << lab << " Minute (ex: 40): "; // Minute
        cin >> m;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Hour (ex: 23) "; // Hour
        cin >> h;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Day (ex: 30): "; // Day
        cin >> d;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Month (ex: 11): "; // Month
        cin >> mm;
        getline(cin, buffer); // clearing buffer

        if(mm > 0){mm -= 1;}

        cout << " -Enter Flight " << lab << " Year (ex: 2018): "; // Year
        cin >> y;
        getline(cin, buffer); // clearing buffer
        y -= 1900;

        if(i == 0)
        {
            st.tm_min = m;
            st.tm_hour = h;
            st.tm_mday = d;
            st.tm_mon = mm;
            st.tm_year = y;
        }else if(i == 1)
        {
            et.tm_min = m;
            et.tm_hour = h;
            et.tm_mday = d;
            et.tm_mon = mm;
            et.tm_year = y;
        }
    }

    if(flights.flightPossible(planes.getPlane(tn), c, &st, &et))
    {
        // Codes
        cout << "Enter 3 letter Starting Airport Code: "; // Starting Code
        getline(cin, sc);
        cout << "Enter 3 letter Ending Airport Code: "; // Ending Code
        getline(cin, ec);

        // Num Passengers
        cout << "Enter number of passengers (max " << mp << "): ";
        cin >> np;
        getline(cin, buffer); // clearing buffer
        while(np > mp)
        {
            cout << "Must be less than " << mp << ": ";
            cin >> np;
            getline(cin, buffer); // clearing buffer
        }

        // Status
        cout << "Enter Status (Active, Cancelled, Completed): "; // Status
        getline(cin, s);
        while((s != "Active") && (s != "Cancelled") && (s != "Completed"))
        {
            cout << "Enter valid input: ";
            getline(cin, s);
        }
    
        Flight f(fid, planes.getPlane(tn), c[0], c[1], c[2], c[3], c[4], st, et, sc, ec, np, s);
        flights.addFlight(f);
    }else
    {
        cout << "Flight with that combination of Planes and Crew is not possible." << endl;
    }
}

// Edits a flight
void editFlight()
{
    string ofid, fid, sc, ec, s, tn;
    string pid, cpid, c1id, c2id, c3id;
    int np, mp;
    struct tm st, et;
    CrewMember* c[5];

    cout << "Enter ID for Flight to update: ";
    getline(cin, ofid);
    while(!flights.flightExists(ofid))
    {
        cout << "Flight with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, ofid);
    }

    cout << "Enter Updated Flight ID: "; // ID
    getline(cin, fid);

    // Crew
    {
        cout << "Enter Updated Crew ID for Pilot: "; // Pilot
        getline(cin, pid);
        while(!crew.crewMemberExists(pid))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, pid);
        }
        c[0] = crew.getCrewMemberByID(pid);
        
        cout << "Enter Updated Crew ID for CoPilot: "; // CoPilot
        getline(cin, cpid);
        while(!crew.crewMemberExists(cpid))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, cpid);
        }
        c[1] = crew.getCrewMemberByID(cpid);

        cout << "Enter Updated Crew ID for Cabin 1: "; // Cabin 1
        getline(cin, c1id);
        while(!crew.crewMemberExists(c1id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c1id);
        }
        c[2] = crew.getCrewMemberByID(c1id);

        cout << "Enter Updated Crew ID for Cabin 2: "; // Cabin 2
        getline(cin, c2id);
        while(!crew.crewMemberExists(c2id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c2id);
        }
        c[3] = crew.getCrewMemberByID(c2id);

        cout << "Enter Updated Crew ID for Cabin 3: "; // Cabin 3
        getline(cin, c3id);
        while(!crew.crewMemberExists(c3id))
        {
            cout << "Crew Member with given ID doesn't exits.\nEnter valid ID: ";
            getline(cin, c3id);
        }
        c[4] = crew.getCrewMemberByID(c3id);
    }

    // Plane
    cout << "Enter Updated Tail Number for Plane: ";
    getline(cin, tn);
    while(!planes.planeExists(tn))
    {
        cout << "Plane with given tail number doesn't exits.\nEnter valid Tail Number: ";
        getline(cin, tn);
    }
    mp = planes.getPlane(tn)->getNumberOfSeats();

    // Getting start and end time
    for(int i = 0; i < 2; i++)
    {
        string lab = "Starting";
        int m,h,d,mm,y;
        if(i == 1) { lab = "Ending";}

        cout << "Enter Updated " << lab << " Time" << endl;

        cout << " -Enter Flight " << lab << " Minute (ex: 40): "; // Minute
        cin >> m;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Hour (ex: 23) "; // Hour
        cin >> h;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Day (ex: 30): "; // Day
        cin >> d;
        getline(cin, buffer); // clearing buffer

        cout << " -Enter Flight " << lab << " Month (ex: 11): "; // Month
        cin >> mm;
        getline(cin, buffer); // clearing buffer

        if(mm > 0){mm -= 1;}

        cout << " -Enter Flight " << lab << " Year (ex: 2018): "; // Year
        cin >> y;
        getline(cin, buffer); // clearing buffer
        y -= 1900;

        if(i == 0)
        {
            st.tm_min = m;
            st.tm_hour = h;
            st.tm_mday = d;
            st.tm_mon = mm;
            st.tm_year = y;
        }else if(i == 1)
        {
            et.tm_min = m;
            et.tm_hour = h;
            et.tm_mday = d;
            et.tm_mon = mm;
            et.tm_year = y;
        }
    }

    if(flights.flightPossible(planes.getPlane(tn), c, &st, &et))
    {
        // Codes
        cout << "Enter Updated 3 letter Starting Airport Code: "; // Starting Code
        getline(cin, sc);
        cout << "Enter Updated 3 letter Ending Airport Code: "; // Ending Code
        getline(cin, ec);

        // Num Passengers
        cout << "Enter Updated number of passengers (max " << mp << "): ";
        cin >> np;
        getline(cin, buffer); // clearing buffer
        while(np > mp)
        {
            cout << "Must be less than " << mp << ": ";
            cin >> np;
            getline(cin, buffer); // clearing buffer
        }

        // Status
        cout << "Enter Updated Status (Active, Cancelled, Completed): "; // Status
        getline(cin, s);
        while((s != "Active") && (s != "Cancelled") && (s != "Completed"))
        {
            cout << "Enter valid input: ";
            getline(cin, s);
        }
    
        flights.deleteFlight(ofid); // Deleting old version of flight
        // Adding updated flight
        Flight f(fid, planes.getPlane(tn), c[0], c[1], c[2], c[3], c[4], st, et, sc, ec, np, s);
        flights.addFlight(f);
    }else
    {
        cout << "Flight with that combination of Planes and Crew is not possible." << endl;
    }
}

// Deletes a flight
void deleteFlight()
{
    string id;
    int p;

    cout << "Enter ID of the Flight: ";
    getline(cin, id);

    while(!flights.flightExists(id))
    {
        cout << "Flight with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, id);
    }

    flights.deleteFlight(id); // Deleting flight
}

// Deletes a flight by status
void deleteFlightByStatus()
{
    string s;
    int p;

    cout << "Enter Status of the Flights to delete (Active, Cancelled, Completed): ";
    getline(cin, s);
    while((s != "Active") && (s != "Cancelled") && (s != "Completed"))
    {
        cout << "Enter valid input: ";
        getline(cin, s);
    }
    
    for(int i = 0; i < flights.getSize(); i++)
    {
        if(flights.getFlight(i)->getStatus() == s)
        {
            flights.deleteFlight(flights.getFlight(i)->getFlightID()); // Deleting flight
        }
    }
}

// Prints a flight
void printFlight()
{
    string id;

    cout << "Enter ID of the Flight: ";
    getline(cin, id);

    while(!flights.flightExists(id))
    {
        cout << "Flight with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, id);
    }

    flights.getFlight(id)->printInfo(); // Printing flight info
}

// Adds passengers to flight
void addPassengers()
{
    string id;
    int p;

    cout << "Enter ID of the Flight: ";
    getline(cin, id);

    while(!flights.flightExists(id))
    {
        cout << "Flight with given ID doesn't exits.\nEnter valid ID: ";
        getline(cin, id);
    }

    int m = planes.getPlane(flights.getFlight(id)->getPlaneTailNumber())->getNumberOfSeats() - flights.getFlight(id)->getNumberOfPassengers();

    cout << "Enter number of passengers to add (max " << m << "): ";
    cin >> p;
    while(p > m)
    {
        cout << "# of passengers to add must be less than " << m << ".\nEnter valid input: ";
        cin >> p;
    }
    getline(cin, buffer); // clearing buffer

    flights.getFlight(id)->addPassengers(p); // Adding Passengers
}