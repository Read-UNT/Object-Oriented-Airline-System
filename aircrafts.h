#ifndef aircrafts_h
#define aircrafts_h

#include <iostream>
#include <vector>
#include <string>
#include "aircraft.h"
#include "flight.h"

using namespace std;

class aircrafts{

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
        
        int passengerCheckerino(int, string);
        int getSeats(int);
        int search(string);
        int getAircraftCount();

        
        aircrafts() {aircraftCount = 0;}
    private:
        int aircraftCount;
        typedef vector<aircraft*> air;
        air aircraftList;
};

#endif