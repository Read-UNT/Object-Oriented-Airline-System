#include <iostream>
#include <vector>
#include <string>
#include "crewMember.h"

//Default functions 'ere

crewMember::crewMember()
{
    
}

crewMember::crewMember(string NAME, string TYPE, string STATUS, int ID)
{
    name = NAME;
    type = TYPE;
    status = STATUS;
    id = ID;
}

//Set functions 'yond 'ere

void crewMember::setName(string nm)
{
    name = nm;
}
void crewMember::setType(string tp)
{
    type = tp;
}
void crewMember::setStatus(string stts)
{
    status = stts;
}
void crewMember::setID(int d)
{
    id = d;
}


//Get functions 'yond 'ere

string crewMember::getName()
{
    return name;
}
string crewMember::getType()
{
    return type;
}
string crewMember::getStatus()
{
    return status;
}
int crewMember::getID()
{
    return id;
}

//Print Things 'yond 'ere

void crewMember::liltimmydroptablePRINT()
{
    cout << "Name: "   << name   << endl;
    cout << "ID: "     << id     << endl;
    cout << "Status: " << status << endl;
    cout << "Type: "   << type   << endl;
}

void crewMember::saving()
{
    cout << "0This should never be called..." << endl;
}

void crewMember::editRating(string x)
{
    cout << "1This should never be called..." << endl;
}
void crewMember::editHoursFlown(double x)
{
    cout << "2This should never be called..." << endl;
}
void crewMember::editPosition(string x)
{
    cout << "3This should never be called..." << endl;
}