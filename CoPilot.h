#ifndef COPILOT_H
#define COPILOT_H

#include "CrewMember.h"

class CoPilot : public CrewMember
{
    public:
        CoPilot();
        CoPilot(string n, string id, string s, string r, int h);
        void setRating(string r);
        void setHours(int h);
        void addHours(int h);
        void printInfo();
        string getRating();
        int getHours();
    private:
        string rating; // A B C D
        int hours;        
};

#endif