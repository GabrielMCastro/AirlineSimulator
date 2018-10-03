#include "PlaneCollection.h"
#include "Plane.h"

PlaneCollection::PlaneCollection()
{
    size = 0;
}

// Adds a plane to the collection
void PlaneCollection::addPlane(Plane a)
{
    planes.push_back(a);
    size++;
}

// by make and model
Plane* PlaneCollection::getPlane(string make, string model)
{
    for(int i = 0; i < size; i++)
    {
        if(planes.at(i).getModel() == model && planes.at(i).getMake() == make)
        {
            return &planes.at(i);
        }
    }
}

// by tail number
Plane* PlaneCollection::getPlane(string t)
{
    for(int i = 0; i < size; i++)
    {
        if(planes.at(i).getTailNumber() == t)
        {
            return &planes.at(i);
        }
    }
}

// by index
Plane* PlaneCollection::getPlane(int i)
{
    return &planes.at(i);
}

// by make and model
void PlaneCollection::deletePlane(string make, string model)
{
    for(int i = 0; i < size; i++)
    {
        if(planes.at(i).getModel() == model && planes.at(i).getMake() == make)
        {
            planes.erase(planes.begin() + i);
            size--;
        }
    }
}

// by tail number
void PlaneCollection::deletePlane(string t)
{
    for(int i = 0; i < size; i++)
    {
        if(planes.at(i).getTailNumber() == t)
        {
            planes.erase(planes.begin() + i);
            size--;
        }
    }
}

// By index
void PlaneCollection::deletePlane(int i)
{
    if(i <= (size - 1))
    {
        planes.erase(planes.begin() + i);
        size--;
    }
}

// Loops through the planes and checks if any have the given tail number
bool PlaneCollection::planeExists(string t)
{
    bool e = false;
    for(int i = 0; i < size; i++)
    {
        if(planes.at(i).getTailNumber() == t)
        {
            e = true;
        }
    }
    return e;
}

// Prints all plane's info
void PlaneCollection::printPlanes()
{
    for(int i = 0; i < size; i++)
    {
        cout << "-- Plane " << (i + 1) << " --" << endl;
        planes.at(i).printInfo();
    }
}

// Returns the size of the collection
int PlaneCollection::getSize()
{
    return size;
}

