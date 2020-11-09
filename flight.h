#ifndef flight_h
#define flight_h

#include <string>
#include <time.h>

using namespace std;

class flight{

    public:
        flight(string, tm, tm, string, string, string, int, int, int, int, int, int);

        void setTailNum(string);
        void setStartDate(tm);
        void setEndDate(tm);
        void setStartCode(string);
        void setEndCode(string);
        void setStatus(string);
        
        void setPilotID(int);
        void setCoPilotID(int);
        void setCrewID1(int);
        void setCrewID2(int);
        void setCrewID3(int);
        void setNumCattle(int);

        string getTailNum();
        string getStartDate();
        tm getStartTime();
        string getEndDate();
        tm getEndTime();
        string getStartCode();
        string getEndCode();
        string getStatus();

        int getPilotID();
        int getCoPilotID();
        int getCrewID1();
        int getCrewID2();
        int getCrewID3();
        int getNumCattle();

    private:
        string tailNum;
        tm startDate;
        tm endDate;
        string startCode;
        string endCode;
        string status;

        int pilotID;
        int copilotID;
        int crewID1;
        int crewID2;
        int crewID3;
        int numCattle;
};

#endif