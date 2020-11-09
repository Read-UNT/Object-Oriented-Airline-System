#ifndef crewMember_h
#define crewMember_h

#include <string>
#include <fstream>

using namespace std;

class crewMember{

    public:
        virtual void liltimmydroptablePRINT();
        
        virtual void saving();
        virtual void editRating(string);
        virtual void editHoursFlown(double);
        virtual void editPosition(string);

        crewMember();

        crewMember(string, string, string, int);

        void setName(string);
        void setType(string);
        void setStatus(string);
        void setID(int);

        string getName();
        string getType();
        string getStatus();
        int getID();

    protected:
        string name;
        string type;
        string status;
        int id;
};

#endif