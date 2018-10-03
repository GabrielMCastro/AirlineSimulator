#ifndef CABIN_H
#define CABIN_H

#include "CrewMember.h"

class Cabin : public CrewMember
{
    public:
        Cabin();
        Cabin(string n, string id, string s, string p);
        void setPosition(string p);
        string getPosition();
        void printInfo();
    private:
        string position; // FirstClass, BusinessClass EconomyFront, EconomyRear, Lead       
};

#endif