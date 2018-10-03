#ifndef PLANE_H
#define PLANE_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Plane
{
    public:
        Plane();
        Plane(string mk, string m, string st, string tn, int s, int r);
        void setMake(string m);
        void setModel(string m);
        void setStatus(string s);
        void setTailNumber(string t);
        void setNumberOfSeats(int s);
        void setRange(int r); // in miles
        void addAssignment(string id);
        string getMake();
        string getModel();
        string getStatus();       
        string getTailNumber();
        int getNumberOfSeats();
        int getRange();
        int getNumAssignments();
        string getAssignment(int i); // by index
        void printInfo();
    private:
        string make;
        string model;
        string status;
        string tailnumber;
        int seatnum;
        int range; // in miles
        vector<string> assignments; // vector of flight ids
};

#endif