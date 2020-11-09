#ifndef crewMembers_h
#define crewMembers_h

#include <iostream>
#include <vector>
#include <string>
#include "crewMember.h"
#include "pilot.h"
#include "copilot.h"
#include "LilTimmyDropTable.h"

using namespace std;

class crewMembers{

    public:
        void menu();
        void add();
        void edit();
        void decimate();
        void printAll();
        void printDetails();
        void save();
        void load();
        void somethingSpecial();
        
        int search(int);
        int getCrewCount();
        crewMembers() {crewCount = 0;}
    private:
        int crewCount;
        typedef vector<crewMember*> crew;
        crew crewList;
};

#endif