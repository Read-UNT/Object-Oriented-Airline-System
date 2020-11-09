#include <iostream>
#include "pilot.h"

//Default constructor

pilot::pilot()
{}

//Gets

double pilot::getHoursFlown()
{
    return hoursFlown;
}

string pilot::getRating()
{
    return rating;
}

//Sets

void pilot::setHoursFlown(double hoursFlownByLilTimmyDropTableux)
{
    hoursFlown = hoursFlownByLilTimmyDropTableux;
}

void pilot::setRating(string ratingOfLilTimmyDropTurtle)
{
    rating = ratingOfLilTimmyDropTurtle;
}