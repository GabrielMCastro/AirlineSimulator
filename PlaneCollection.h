#ifndef PLANECOLLECTION_H
#define PLANECOLLECTION_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Plane.h"

using namespace std;

class PlaneCollection 
{
    public:
        PlaneCollection();
        void addPlane(Plane p);
        Plane* getPlane(string make, string model);
        Plane* getPlane(string t);
        Plane* getPlane(int i);
        void deletePlane(string make, string model);
        void deletePlane(string t);
        void deletePlane(int i);
        void printPlanes();
        int getSize();
        bool planeExists(string t);
    private:
        vector<Plane> planes;
        int size;
};

#endif