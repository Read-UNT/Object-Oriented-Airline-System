#include <iostream>
#include <vector>
#include <string>
#include "aircraft.h"

//Default constructor 

aircraft::aircraft(string mk, string mdl, string tlnm, string rng, string stts, int nmsts)
{
    make = mk;
    model = mdl;
    tailNum = tlnm;
    range = rng;
    status = stts;
    numSeats = nmsts;
}

//Set functions

void aircraft::setMake(string mk)
{
    make = mk;
}
void aircraft::setModel(string mdl)
{
    model = mdl;
}
void aircraft::setTailNum(string tlnm)
{
    tailNum = tlnm;
}
void aircraft::setRange(string rng)
{
    range = rng;
}
void aircraft::setStatus(string stts)
{
    status = stts;
}
void aircraft::setNumSeats(int nmsts)
{
    numSeats = nmsts;
}

// Get functions

string aircraft::getMake()
{
    return make;
}
string aircraft::getModel()
{
    return model;
}
string aircraft::getTailNum()
{
    return tailNum;
}
string aircraft::getRange()
{
    return range;
}
string aircraft::getStatus()
{
    return status;
}
int aircraft::getNumSeats()
{
    return numSeats;
}