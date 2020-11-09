#ifndef flights_h
#define flights_h

#include <iostream>
#include <vector>
#include <string>
#include "flight.h"
#include "crewMembers.h"
#include "aircrafts.h"

using namespace std;

class flights{

    public:
        void menu(crewMembers*, aircrafts*);
        void add(crewMembers*, aircrafts*);
        void edit();
        void decimate();
        void printAll();
        void printDetails();
        
        void save();
        void load();
        void checkStatus();

        string timeSearch();

        int search(string, string);
        int getFlightCount();
        int check(string, int, int, int, int, int, int, int, int, int, int);
        flights() {flightCount = 0;}
        
    private:
        int flightCount;
        typedef vector<flight*> fly;
        fly flightList;
};

#endif