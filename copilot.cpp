#include <iostream>
#include "copilot.h"

//Defaults

copilot::copilot()
{}

//Gets

double copilot::getHoursFlown()
{
    return hoursFlown;
}

string copilot::getRating()
{
    return rating;
}

//Sets

void copilot::setHoursFlown(double hoursFlownByLilTimmyDropTableux)
{
    hoursFlown = hoursFlownByLilTimmyDropTableux;
}

void copilot::setRating(string ratingOfLilTimmyDropTurtle)
{
    rating = ratingOfLilTimmyDropTurtle;
}