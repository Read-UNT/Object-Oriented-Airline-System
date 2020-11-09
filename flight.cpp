#include <iostream>
#include <vector>
#include <string>
#include "flight.h"

//Default constructor

flight::flight(string tlnm, tm sd, tm ed, string sc, string ec, string stts, int pid, int cpid, int cid1, int cid2, int cid3, int nc)
{
    tailNum = tlnm;
    startDate = sd;
    endDate = ed;
    startCode = sc;
    endCode = ec;
    status = stts;

    pilotID = pid;
    copilotID = cpid;
    crewID1 = cid1;
    crewID2 = cid2;
    crewID3 = cid3;
    numCattle = nc;
}

//Set functions

void flight::setTailNum(string tlnm)
{
    tailNum = tlnm;
}
void flight::setStartDate(tm sd)
{
    startDate = sd;
}
void flight::setEndDate(tm ed)
{
    endDate = ed;
}
void flight::setStartCode(string sc)
{
    startCode = sc;
}
void flight::setEndCode(string ec)
{
    endCode = ec;
}
void flight::setStatus(string stts)
{
    status = stts;
}
        
void flight::setPilotID(int pid)
{
    pilotID = pid;
}
void flight::setCoPilotID(int cpid)
{
    copilotID = cpid;
}
void flight::setCrewID1(int cid1)
{
    crewID1 = cid1;
}
void flight::setCrewID2(int cid2)
{
    crewID2 = cid2;
}
void flight::setCrewID3(int cid3)
{
    crewID3 = cid3;
}
void flight::setNumCattle(int nc)
{
    numCattle = nc;
}

//Get Functions

string flight::getTailNum()
{
    return tailNum;
}
string flight::getStartDate()
{
    return asctime(&startDate);
}
tm flight::getStartTime()
{
    return startDate;
}
string flight::getEndDate()
{
    return asctime(&endDate);
}
tm flight::getEndTime()
{
    return endDate;
}
string flight::getStartCode()
{
    return startCode;
}
string flight::getEndCode()
{
    return endCode;
}
string flight::getStatus()
{
    return status;
}

int flight::getPilotID()
{
    return pilotID;
}
int flight::getCoPilotID()
{
    return copilotID;
}
int flight::getCrewID1()
{
    return crewID1;
}
int flight::getCrewID2()
{
    return crewID2;
}
int flight::getCrewID3()
{
    return crewID3;
}
int flight::getNumCattle()
{
    return numCattle;
}