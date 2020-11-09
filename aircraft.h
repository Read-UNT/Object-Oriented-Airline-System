#ifndef aircraft_h
#define aircraft_h

#include <string>

using namespace std;

class aircraft{

    public:
        aircraft(string, string, string, string, string, int);

        void setMake(string);
        void setModel(string);
        void setTailNum(string);
        void setRange(string);
        void setStatus(string);
        void setNumSeats(int);

        string getMake();
        string getModel();
        string getTailNum();
        string getRange();
        string getStatus();
        int getNumSeats();

    private:
        string make;
        string model;
        string tailNum;
        string range;
        string status;
        int numSeats;
};

#endif