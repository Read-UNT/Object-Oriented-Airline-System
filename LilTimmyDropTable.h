#ifndef liltimmydroptable_h
#define liltimmydroptable_h

#include "crewMember.h"
#include <fstream>

using namespace std;

class liltimmydroptable : public crewMember
{
    public:
        liltimmydroptable();

        liltimmydroptable(string NAME, string TYPE, string STATUS, int ID, string ps) : crewMember(NAME, TYPE, STATUS, ID)
        {
            position = ps;
        }

        string getPos();
        void setPos(string);
        virtual void liltimmydroptablePRINT()
        {
            crewMember::liltimmydroptablePRINT();
            cout << "Position: " << position << endl << endl;
        }

        virtual void saving()
        {
            ofstream tempOut;

            tempOut.open("crew.txt", ofstream::app);

            tempOut << position << endl;

            tempOut.close();
        }

        virtual void editPosition(string tempPos)
        {
            position = tempPos;
        }

    protected:
        string position;
};

#endif