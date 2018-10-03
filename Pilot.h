#ifndef PILOT_H
#define PILOT_H

#include "CrewMember.h"

class Pilot : public CrewMember
{
    public:
        Pilot();
        Pilot(string n, string id, string s, string r, int h);
        void setRating(string r);
        void setHours(int h);
        void addHours(int h);
        void printInfo();
        string getRating();
        int getHours();
    private:
        string rating; // A B C D F
        int hours;        
};

#endif