#ifndef pilot_h
#define pilot_h

#include "crewMember.h"
#include <fstream>

using namespace std;

class pilot : public crewMember
{
    public:
        pilot();

        pilot(string NAME, string TYPE, string STATUS, int ID, string rtng, double hrs) : crewMember(NAME, TYPE, STATUS, ID)
        {
            rating = rtng;
            hoursFlown = hrs; 
        }
        double getHoursFlown();
        string getRating();

        void setHoursFlown(double);
        void setRating(string);

        virtual void liltimmydroptablePRINT()
        {
            crewMember::liltimmydroptablePRINT();
            cout << "Rating: "        << rating     << endl;
            cout << "Pilot Hours: "   << hoursFlown << endl << endl;
        }

        virtual void saving()
        {
            ofstream tempOut;

            tempOut.open("crew.txt", ofstream::app);

            tempOut << rating     << endl;
            tempOut << hoursFlown << endl;

            tempOut.close();
        }

        virtual void editRating(string tempRate)
        {
            rating = tempRate;
        }

        virtual void editHoursFlown(double tempHour)
        {
            hoursFlown = tempHour;
        }

    protected:
        double hoursFlown;
        string rating;
};

#endif