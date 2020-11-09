#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "flights.h"
#include "aircrafts.h"
#include "crewMembers.h"

/*

Function : Print Menu
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints secondary menu of options for flights

*/

void flights::menu(crewMembers* TempityTemp, aircrafts* TempityTemp2ElectricBoogaloo)
{
    int choice;

    do
    {
        checkStatus();

        if(flightCount == 0)
        {
            load();
        }

        cout << "Flight Menu" << endl << endl;

        cout << "0. Exit to Main Menu" << endl;
        cout << "1. Add a Flight"      << endl;
        cout << "2. Edit a Flight"     << endl;
        cout << "3. Delete a Flight"   << endl;
        cout << "4. Print One Flight"  << endl;
        cout << "5. Print All Flights" << endl;
        cout << "Enter your choice(0-5): ";
        cin >> choice;

        //Flushing the input stream
        cin.ignore();

        cout << endl;

        if(choice == 0)
        {
            save();
            cout << "Now exiting to Main Menu." << endl << endl;
        }
        
        //Mild error handling
        
        if(choice < 0 || choice > 5)
        {
            cout << "You did not enter a possible choice..." << endl;
        }
    
       //Switch statement to run the function of the choice the user made
    
       switch(choice)
       {
            case 1: add(TempityTemp, TempityTemp2ElectricBoogaloo); break;
            case 2: edit();          break;
            case 3: decimate();      break;
            case 4: printDetails();  break;
            case 5: printAll();      break;
       }

    }while(choice != 0);

}

/*

Function : Add a Flight
Parameters : None
Return : Nothing, void function.
Description : 
 - Adds a flight to the list

*/

void flights::add(crewMembers* TempityTemp, aircrafts* TempityTemp2ElectricBoogaloo)
{
    string tailnum, status;
    string startcode, endcode;

    int pilotID, copilotID;
    int crewID1, crewID2, crewID3;
    int numcattle, found;

    int change = 0, checks;

    int x = 0, y = 0, z = 0;
    string tail;

    int id = 0;

    tm startdate, enddate;
    flight *flightTemp;
    aircrafts *aircraftTemp;
    crewMembers *crewTemp;

    ifstream fin, fin1;

    fin.open("randomThing.txt");
    fin1.open("cattle.txt");

    fin >> x;
    //fin.ignore();

    fin1 >> y;
    //fin1.ignore();

    status = "Available";

    cout << "Flight listed as \"Available\" automatically, you cannot add a completed or cancelled flight." << endl; 

    vector <string> tails;

    for(int i = 0; i < y; i++)
    {
        fin >> tail;
        tails.push_back(tail);
        fin.ignore();
    }

    cout << "Enter tail number: ";
    getline(cin, tailnum);
    do
    {
        for(int i = 0; i < x; i++)
        {
            if(tails[i] == tailnum)
            {
                z++;
                break;
            }
        }

        if(z == 0)
        {
            cout << "Tail number is not currently on an aircraft. Re-enter: ";
            getline(cin, tailnum);
        }

    }while(z == 0);
    z = 0;
    
    //cin.ignore(); 

    vector <int> ids;

    for(int i = 0; i < y; i++)
    {
        fin1 >> id;
        ids.push_back(id);
        //fin1.ignore();
    }

    cout << "Enter pilot ID: ";
    cin >> pilotID;
    cin.ignore();
    found = TempityTemp -> search(pilotID);
    while(found == -1)
    {
        cout << "ID not found." << endl;
        cout << "Enter pilot ID: ";
        cin >> pilotID;
        found = TempityTemp -> search(pilotID);
    }

    cout << "Enter copilot ID: ";
    cin >> copilotID;
    cin.ignore();
    found = TempityTemp -> search(copilotID);
    while(found == -1)
    {
        cout << "ID not found." << endl;
        cout << "Enter copilot ID: ";
        cin >> copilotID;
        found = TempityTemp -> search(copilotID);
    }
    
    cout << "Enter Crew ID 1: ";
    cin >> crewID1;
    cin.ignore();
    found = TempityTemp -> search(crewID1);
    while(found == -1)
    {
        cout << "ID not found." << endl;
        cout << "Enter crew ID: ";
        cin >> crewID1;
        found = TempityTemp -> search(crewID1);
    }

    cout << "Enter Crew ID 2: ";
    cin >> crewID2;
    cin.ignore();
    found = TempityTemp -> search(crewID2);
    while(found == -1)
    {
        cout << "ID not found." << endl;
        cout << "Enter crew ID: ";
        cin >> crewID2;
        found = TempityTemp -> search(crewID2);
    }

    cout << "Enter Crew ID 3: ";
    cin >> crewID3;
    cin.ignore();
    found = TempityTemp -> search(crewID3);
    while(found == -1)
    {
        cout << "ID not found." << endl;
        cout << "Enter crew ID: ";
        cin >> crewID3;
        found = TempityTemp -> search(crewID3);
    }

    fin1.close();
    fin.close();

    //start date user input

    /* Broken for some reason? It's whoever wrote time.h's fault. got a 71 :( might be maybe my fault
    cout << "Is daylight savings time active during the start of the flight? (0 = inactive or 1 = active): ";
    cin >> startdate -> tm_isdst;
    cin.ignore();
    while(startdate -> tm_isdst < 0 || startdate -> tm_isdst > 1)
    {
        cout << "Daylight Savings Time value out of range. Re-enter (0 or 1): ";
        cin >> startdate -> tm_isdst;
        cin.ignore();

    }
    */

    cout << "Year flight is departing: ";
    cin >> startdate.tm_year;
    cin.ignore();
    startdate.tm_year -= 1900;

    cout << "Month flight is departing (0-11): ";
    cin >> startdate.tm_mon;
    cin.ignore();
    while(startdate.tm_mon < 0 || startdate.tm_mon > 11)
    {
        cout << "Month out of range. Re-enter (0-11): ";
        cin >> startdate.tm_mon;
        cin.ignore();
    }

    cout << "Day of the month flight is departing (1-31): ";
    cin >> startdate.tm_mday;
    cin.ignore();
    while(startdate.tm_mday < 1 || startdate.tm_mday > 31)
    {
        cout << "Day is out of range. Re-enter(1-31): ";
        cin >> startdate.tm_mday;
        cin.ignore();
    }

    cout << "Day of the week flight is departing (Sunday = 0, 0-6): ";
    cin >> startdate.tm_wday;
    cin.ignore();
    while(startdate.tm_wday < 0 || startdate.tm_wday > 6)
    {
        cout << "Day is out of range. Re-enter(0-6): ";
        cin >> startdate.tm_wday;
        cin.ignore();
    } 

    cout << "Hour flight is departing (0-23): ";
    cin >> startdate.tm_hour;
    cin.ignore();
    while(startdate.tm_hour < 0 || startdate.tm_hour > 23 )
    {
        cout << "Hour is out of range. Re-enter(0-23): ";
        cin >> startdate.tm_hour;
        cin.ignore();
    }

    cout << "Minute flight is departing (0-59): ";
    cin >> startdate.tm_min;
    cin.ignore();
    while(startdate.tm_min < 0 || startdate.tm_min > 59)
    {
        cout << "Minute is out of range. Re-enter(0-59): ";
        cin >> startdate.tm_min;
        cin.ignore();
    }

    startdate.tm_sec = 00;

    //end of start date input

    //Check start date

    if(check(tailnum, pilotID, copilotID, crewID1, crewID2, crewID3, startdate.tm_year, startdate.tm_mon, startdate.tm_mday, startdate.tm_hour, startdate.tm_min))
    {
        return;
    }

    //beginning of end date input

    cout << "Year flight is arriving: ";
    cin >> enddate.tm_year;
    cin.ignore();
    enddate.tm_year -= 1900;
    while(startdate.tm_year > enddate.tm_year)
    {
        cout << "Flight cannot go back in time. Re-enter: ";
        cin >> enddate.tm_year;
        cin.ignore();
        enddate.tm_year -= 1900;
    }

    cout << "Month flight is arriving (0-11): ";
    cin >> enddate.tm_mon;
    cin.ignore();
    while(enddate.tm_mon < 0 || enddate.tm_mon > 11)
    {
        cout << "Month out of range. Re-enter (0-11): ";
        cin >> enddate.tm_mon;
        cin.ignore();
    }
    while(startdate.tm_year == enddate.tm_year && startdate.tm_mon > enddate.tm_mon)
    {
        cout << "Flight cannot go back in time. Re-enter (0-11): ";
        cin >> enddate.tm_mon;
        cin.ignore();
    }

    cout << "Day of the month flight is arriving (1-31): ";
    cin >> enddate.tm_mday;
    cin.ignore();
    while(enddate.tm_mday < 1 || enddate.tm_mday > 31)
    {
        cout << "Day is out of range. Re-enter(1-31): ";
        cin >> enddate.tm_mday;
        cin.ignore();
    }
    while(startdate.tm_mon == enddate.tm_mon && startdate.tm_mday > enddate.tm_mday)
    {
        cout << "Flight cannot go back in time. Re-enter(1-31): ";
        cin >> enddate.tm_mday;
        cin.ignore();
    }

    change = enddate.tm_mday - startdate.tm_mday;

    cout << "Day of the week flight is arriving (Sunday = 0, 0-6): ";
    cin >> enddate.tm_wday;
    cin.ignore();
    while(enddate.tm_wday < 0 || enddate.tm_wday > 6)
    {
        cout << "Flights do not last that long. Re-enter(0-6): ";
        cin >> enddate.tm_wday;
        cin.ignore();
    }
    while(enddate.tm_wday != startdate.tm_wday + change)
    {
        cout << "Day is out of correct range. Re-enter(0-6): ";
        cin >> enddate.tm_wday;
        cin.ignore();
    }
    /*
    while(startdate.tm_wday > enddate.tm_wday)
    {
        if(startdate.tm_wday == 6 && enddate.tm_wday == 0)
        {
            break;
        }
        else
        {
            cout << "Flight cannot go back in time. Re-enter(0-6): ";
            cin >> enddate.tm_wday;
            cin.ignore();
        }
    }
    */

    cout << "Please allow at minimum, a 1 hour gap between flights." << endl;
    cout << "Hour flight is arriving (0-23): ";
    cin >> enddate.tm_hour;
    cin.ignore();
    while(enddate.tm_hour < 0 || enddate.tm_hour > 23)
    {
        cout << "Hour is out of range. Re-enter(0-23): ";
        cin >> enddate.tm_hour;
        cin.ignore();
    }
    while(startdate.tm_mday == enddate.tm_mday && startdate.tm_hour > enddate.tm_hour)
    {
        cout << "Flight cannot go back in time. Re-enter(0-23): ";
        cin >> enddate.tm_hour;
        cin.ignore();
    }

    cout << "Minute flight is arriving (0-59): ";
    cin >> enddate.tm_min;
    cin.ignore();
    while(enddate.tm_min < 0 || enddate.tm_min > 59)
    {
        cout << "Minute is out of range. Re-enter(0-59): ";
        cin >> enddate.tm_min;
        cin.ignore();
    }
    while(startdate.tm_hour == enddate.tm_hour && startdate.tm_min >= enddate.tm_min && startdate.tm_mday == enddate.tm_mday)
    {
        cout << "Flight cannot go back in time. Re-enter(0-59): ";
        cin >> enddate.tm_min;
        cin.ignore();
    }
    if(enddate.tm_min > 30)
    {
        enddate.tm_hour += 1;
    }

    enddate.tm_sec = 00;

    //end of end date input

    cout << "Enter departing airport code: ";
    getline(cin, startcode);

    cout << "Enter arriving airport code: ";
    getline(cin, endcode);

    cout << "Enter number of passengers: ";
    cin >> numcattle;
    cin.ignore();
    found = TempityTemp2ElectricBoogaloo -> passengerCheckerino(numcattle, tailnum);
    while(found == -1)
    {
        cout << "Too many passengers." << endl;
        cout << "Enter new number of passengers:";
        cin >> numcattle;
        found = TempityTemp2ElectricBoogaloo -> passengerCheckerino(numcattle, tailnum);
    }
    //Check end date

    if(check(tailnum, pilotID, copilotID, crewID1, crewID2, crewID3, enddate.tm_year, enddate.tm_mon, enddate.tm_mday, enddate.tm_hour, enddate.tm_min))
    {
        return;
    }

    //Check flight is not going back in time
    //if(startdate.tm_year < )

    cout << "Flight scheduled!" << endl << endl;
    flightTemp = new flight(tailnum, startdate, enddate, startcode, endcode, status, pilotID, copilotID, crewID1, crewID2, crewID3, numcattle);
    flightList.push_back(flightTemp);
    flightCount++;
    
}

/*

Function : Edit a Flight
Parameters : None
Return : Nothing, void function.
Description : 
 - Edits a flight specified by user

*/

void flights::edit()
{
    
    if(flightList.size() == 0)
    {
        cout << "There are no flights to edit." << endl;
        return;
    }

    string tailnum, time, status;
    int found = 0, choice, pilotID, copilotID, crewID1, crewID2, crewID3, numcattle;

    cout << "List of flights to choose from" << endl;

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        cout << "Selection " << i+1 << endl;
        cout << "Tail Number: " << flightList[i] -> getTailNum()   << endl;
        cout << "Start Date: "  << flightList[i] -> getStartDate() << endl << endl; 
    }
    cout << "Selection (0-" << flightList.size() <<  "): ";
    cin >> found;
    cin.ignore();

    while(found < 1 || found > flightList.size())
    {
        cout << "You did not pick a flight from the list. Re-enter." << endl;
        cout << "Selection (0-" << flightList.size() <<  "): ";
        cin >> found;
        cin.ignore();
    }

    found -= 1;

    /*
    do
    {
        cout << "Enter the Tail Number: ";
        getline(cin, tailnum);

        cout << "Enter the time the flight is departing" << endl;
        time = timeSearch();

        found = search(tailnum, time);

        if(search(tailnum, time) == -1)
        {
            cout << "Matching flight not found." << endl;
        }

    }while(search(tailnum, time) == -1);
    */

    cout << "What part of the flight involving aircraft tail number "<< flightList[found] -> getTailNum() << " do you want to change?" << endl;

    do
    {
        cout << "(0) Exit Edit Menu"      << endl;
        cout << "(1) Pilot ID"            << endl;
        cout << "(2) CoPilot ID"          << endl;
        cout << "(3) Crew ID 1"           << endl;
        cout << "(4) Crew ID 2"           << endl;
        cout << "(5) Crew ID 3"           << endl;
        cout << "(6) Number of Seats"     << endl;
        cout << "(7) Flight Status"       << endl;
        cout << "Option(0-7): ";
        cin >> choice;
        cin.ignore();

     
        while(choice < 0 || choice > 7)
        {
            cout << "You did not enter a possible choice..." << endl;
            cout << "Option(0-7): ";
            cin >> choice;
            cin.ignore();
        }

        switch(choice)
        {
            case 1:
                cout << "Enter new Pilot ID: ";
                cin >> pilotID;
                cin.ignore();
                flightList[found] -> setPilotID(pilotID);
                break;

            case 2:
                cout << "Enter new CoPilot ID: ";
                cin >> copilotID;
                cin.ignore();
                flightList[found] -> setCoPilotID(copilotID);
                break;
            case 3:
                cout << "Enter new Crew ID 1: ";
                cin >> crewID1;
                cin.ignore();
                flightList[found] -> setCrewID1(crewID1);
                break;
            case 4:
                cout << "Enter new Crew ID 2: ";
                cin >> crewID2;
                cin.ignore();
                flightList[found] -> setCrewID2(crewID2);
                break;
            case 5:
                cout << "Enter new Crew ID 3: ";
                cin >> crewID3;
                cin.ignore();
                flightList[found] -> setCrewID3(crewID3);
                break;
            case 6:
                cout << "Enter new number of passengers: ";
                cin >> numcattle;
                cin.ignore();
                flightList[found] -> setNumCattle(numcattle);
                break;
            case 7:
                cout << "Enter new flight status: ";
                cout << "(1) Active"    << endl;
                cout << "(2) Cancelled" << endl;
                cout << "(3) Completed" << endl;
                cout << "Option(1-3): ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        status = "Active";
                        break;
                    case 2:
                        status = "Cancelled";
                        break;
                    case 3:
                        status = "Completed";
                        break;
                }
                flightList[found] -> setStatus(status);
                break;

        }

    }while(choice != 0);

}

/*

Function : Delete a Flight
Parameters : None
Return : Nothing, void function.
Description : 
 - Deletes a flight specified by the user

*/

void flights::decimate()
{
    if(flightList.size() == 0)
    {
        cout << "There are no flights to delete." << endl;
        return;
    }

    int found;
    string tailnum, time;

    cout << "List of flights to choose from" << endl;

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        cout << "Selection " << i+1 << endl;
        cout << "Tail Number: " << flightList[i] -> getTailNum()   << endl;
        cout << "Start Date: "  << flightList[i] -> getStartDate() << endl << endl; 
    }
    cout << "Selection (0-" << flightList.size() <<  "): ";
    cin >> found;
    cin.ignore(); 

    while(found < 1 || found > flightList.size())
    {
        cout << "You did not pick a flight from the list. Re-enter." << endl;
        cout << "Selection (0-" << flightList.size() <<  "): ";
        cin >> found;
        cin.ignore();
    }

    found -= 1;

    /*
    do
    {
        cout << "Enter the Tail Number: ";
        getline(cin, tailnum);

        cout << "Enter the time the flight is departing" << endl;
        time = timeSearch();

        found = search(tailnum, time);

        if(search(tailnum, time) == -1)
        {
            cout << "Matching flight not found." << endl;
        }

    }while(search(tailnum, time) == -1);
    */

    flightList.erase(flightList.begin() + found);
    flightCount--;

    save();
}

/*

Function : Search Flights
Parameters : None
Return : Nothing, void function.
Description : 
 - Finds a specific flight given direction by user

*/

int flights::search(string tailnum, string startTime)
{
    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        if(flightList[i] -> getTailNum() == tailnum)
        {
            if(flightList[i] -> getStartDate().compare(startTime))
            {
                return i;
            }
        }
    }

    return -1;
}

/*

Function : Search Time
Parameters : None
Return : Nothing, void function.
Description : 
 - Finds the time given by special user entry

*/

string flights::timeSearch()
{
    tm startdate;

    cout << "Year flight is departing: ";
    cin >> startdate.tm_year;
    cin.ignore();
    startdate.tm_year -= 1900;

    cout << "Month flight is departing (0-11): ";
    cin >> startdate.tm_mon;
    cin.ignore();
    while(startdate.tm_mon < 0 || startdate.tm_mon > 11)
    {
        cout << "Month out of range. Re-enter (0-11): ";
        cin >> startdate.tm_mon;
        cin.ignore();

    }

    cout << "Day of the month flight is departing (1-31): ";
    cin >> startdate.tm_mday;
    cin.ignore();
    while(startdate.tm_mday < 1 || startdate.tm_mday > 31)
    {
        cout << "Day is out of range. Re-enter(1-31): ";
        cin >> startdate.tm_mday;
        cin.ignore();

    }

    cout << "Day of the week flight is departing (Sunday = 0, 0-6): ";
    cin >> startdate.tm_wday;
    cin.ignore();
    while(startdate.tm_wday < 0 || startdate.tm_wday > 6)
    {
        cout << "Day is out of range. Re-enter(0-6): ";
        cin >> startdate.tm_wday;
        cin.ignore();

    } 

    cout << "Hour flight is departing (0-23): ";
    cin >> startdate.tm_hour;
    cin.ignore();
    while(startdate.tm_hour < 0 || startdate.tm_hour > 23)
    {
        cout << "Hour is out of range. Re-enter(0-23): ";
        cin >> startdate.tm_hour;
        cin.ignore();
        
    }

    cout << "Minute flight is departing (0-59): ";
    cin >> startdate.tm_min;
    cin.ignore();
    while(startdate.tm_min < 0 || startdate.tm_min > 59)
    {
        cout << "Minute is out of range. Re-enter(0-59): ";
        cin >> startdate.tm_min;
        cin.ignore();
        
    }

    return asctime(&startdate);
}

/*

Function : Check
Parameters : None
Return : Nothing, void function.
Description : 
 - Checks time of current entry against database to disallow interfering flight scheduling

*/

int flights::check(string tail, int pilot, int copilot, int crew1, int crew2, int crew3, int year, int month, int mday, int hour, int min)
{
    int hour1 = 0, x = 1;

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        if(flightList[i] -> getTailNum() == tail || flightList[i] -> getPilotID() == pilot || flightList[i] -> getCoPilotID() == copilot || 

        flightList[i] -> getCrewID1() == crew1 || flightList[i] -> getCrewID1() == crew2 || flightList[i] -> getCrewID1() == crew3 || 

        flightList[i] -> getCrewID2() == crew1 || flightList[i] -> getCrewID2() == crew2 || flightList[i] -> getCrewID2() == crew3 ||

        flightList[i] -> getCrewID3() == crew1 || flightList[i] -> getCrewID3() == crew2 || flightList[i] -> getCrewID3() == crew3)
        {
            tm temp = flightList[i] -> getStartTime(), temp2 = flightList[i] -> getEndTime();
            
            if(temp.tm_year == year)
            {
                if(temp.tm_mon == month)
                {
                    if(temp.tm_mday == mday)
                    {
                        if(temp2.tm_min > 30)
                        {
                            temp2.tm_hour += 1;
                        }
                        if(temp.tm_hour <= hour && temp2.tm_hour + 1 > hour)
                        {
                            cout << "Plane or member of the crew is already scheduled for this time." << endl;
                            cout << "Please allow at minimum, a 1 hour gap between flights."          << endl << endl;
                            return -1;
                        }
                    }

                    if(temp.tm_mday == temp2.tm_mday - 1)
                    {
                        hour1 = x + temp2.tm_hour;

                        if(temp2.tm_min > 30)
                        {
                            temp2.tm_hour += 1;
                        }
                        if(hour < hour1)
                        {
                            cout << "Plane or member of the crew is already scheduled for this time." << endl;
                            cout << "Please allow at minimum, a 1 hour gap between flights."          << endl << endl;
                            return -1;
                        }
                    }
                }

                if(temp.tm_mon == temp2.tm_mon - 1)
                {
                    hour1 = x + temp2.tm_hour;

                    if(temp2.tm_min > 30)
                    {
                        temp2.tm_hour += 1;
                    }
                    if(hour < hour1)
                    {
                        cout << "Plane or member of the crew is already scheduled for this time." << endl;
                        cout << "Please allow at minimum, a 1 hour gap between flights."          << endl << endl;
                        return -1;
                    }
                }
            }

            if(temp.tm_year == temp2.tm_year - 1)
            {
                hour1 = x + temp2.tm_hour;

                if(temp2.tm_min > 30)
                {
                    temp2.tm_hour += 1;
                }
                if(hour < hour1)
                {
                    cout << "Plane or member of the crew is already scheduled for this time." << endl;
                    cout << "Please allow at minimum, a 1 hour gap between flights."          << endl << endl;
                    return -1;
                }
            }
        }
    }

    return 0;
}

/*

Function : Print All Flights
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints all flights in existence

*/

void flights::printAll()
{
    if(flightList.size() == 0)
    {
        cout << "There are no flights to print." << endl;
        return;
    }

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        cout << "Tail Number: "            << flightList[i] -> getTailNum()   << endl;
        cout << "Pilot ID: "               << flightList[i] -> getPilotID()   << endl;
        cout << "CoPilot ID: "             << flightList[i] -> getCoPilotID() << endl;
        cout << "Crew ID 1: "              << flightList[i] -> getCrewID1()   << endl;
        cout << "Crew ID 2: "              << flightList[i] -> getCrewID1()   << endl;
        cout << "Crew ID 3: "              << flightList[i] -> getCrewID1()   << endl;
        cout << "Start Date: "             << flightList[i] -> getStartDate() << "End Date: "              << flightList[i] -> getEndDate();
        cout << "Departing Airport Code: " << flightList[i] -> getStartCode() << endl;
        cout << "Arriving Airport Code: " << flightList[i] -> getEndCode()    << endl;
        cout << "Number of Seats: "        << flightList[i] -> getNumCattle() << endl;
        cout << "Flight Status: "          << flightList[i] -> getStatus()    << endl << endl;
    }
}

/*

Function : Print a Flight
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints a single flight, specified by user

*/

void flights::printDetails()
{
    if(flightList.size() == 0)
    {
        cout << "There are no flights to print." << endl;
        return;
    }

    string tailnum, time;
    int found;

    cout << "List of flights to choose from" << endl;

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        cout << "Selection " << i+1 << endl;
        cout << "Tail Number: " << flightList[i] -> getTailNum()   << endl;
        cout << "Start Date: "  << flightList[i] -> getStartDate() << endl << endl; 
    }
    cout << "Selection (1-" << flightList.size() <<  "): ";
    cin >> found;
    cin.ignore(); 

    while(found < 1 || found > flightList.size())
    {
        cout << "You did not pick a flight from the list. Re-enter." << endl;
        cout << "Selection (0-" << flightList.size() <<  "): ";
        cin >> found;
        cin.ignore();
    }

    found -= 1;
    
    cout << "Tail Number: "            << flightList[found] -> getTailNum()   << endl;
    cout << "Pilot ID: "               << flightList[found] -> getPilotID()   << endl;
    cout << "CoPilot ID: "             << flightList[found] -> getCoPilotID() << endl;
    cout << "Crew ID 1: "              << flightList[found] -> getCrewID1()   << endl;
    cout << "Crew ID 2: "              << flightList[found] -> getCrewID1()   << endl;
    cout << "Crew ID 3: "              << flightList[found] -> getCrewID1()   << endl;
    cout << "Start Date: "             << flightList[found] -> getStartDate() << " End Date: "              << flightList[found] -> getEndDate();
    cout << "Departing Airport Code: " << flightList[found] -> getStartCode() << endl;
    cout << "Arriving Airport Code: "  << flightList[found] -> getEndCode()   << endl;
    cout << "Number of Seats: "        << flightList[found] -> getNumCattle() << endl;
    cout << "Flight Status: "          << flightList[found] -> getStatus()    << endl << endl;
    
}

/*

Function : Save Flight
Parameters : None
Return : Nothing, void function.
Description : 
 - Saves planned flights to file

*/

void flights::save()
{
    ofstream fout;

    fout.open("flight.txt");

    fout << flightCount << endl;

    for(int i = 0; i < flightCount; i++)
    {
        //string
        fout << flightList[i] -> getTailNum()   << endl;

        //tms
        fout << flightList[i] -> getStartDate();
        fout << flightList[i] -> getEndDate();

        //strings
        fout << flightList[i] -> getStartCode() << endl;
        fout << flightList[i] -> getEndCode()   << endl;
        fout << flightList[i] -> getStatus()    << endl;

        //ints
        fout << flightList[i] -> getPilotID()   << endl;
        fout << flightList[i] -> getCoPilotID() << endl;
        fout << flightList[i] -> getCrewID1()   << endl;
        fout << flightList[i] -> getCrewID1()   << endl;
        fout << flightList[i] -> getCrewID1()   << endl;
        fout << flightList[i] -> getNumCattle() << endl;
    }

    fout.close();
}

/*

Function : Load Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Loads flights from file

*/

void flights::load()
{
    string tailnum, startCode, endCode, status;
    string wday, mon, wday1, mon1;
    tm startdate, enddate;
    int pilotID = 0, copilotID = 0, crew1 = 0, crew2 = 0, crew3 = 0, numCattle = 0;
    flight *temp;
    char trash;

    ifstream fin;

    fin.open("flight.txt");
    if(fin.fail())
    {
        cout << "No Flight load file found or loaded." << endl << endl;
        return;
    }
    else
    {
        cout << "Flight Load file found and loaded." << endl << endl;
    }

    fin >> flightCount;
    fin.ignore();

    for(int i = 0; i < flightCount; i++)
    {
        getline(fin, tailnum);

        fin >> wday >> mon >> startdate.tm_mday >> startdate.tm_hour >> trash >> startdate.tm_min >> trash >> startdate.tm_sec >> startdate.tm_year;
        fin.ignore();
        fin >> wday1 >> mon1 >> enddate.tm_mday >> enddate.tm_hour >> trash >> enddate.tm_min >> trash >>enddate.tm_sec >> enddate.tm_year;
        fin.ignore();

        startdate.tm_year -= 1900;
        enddate.tm_year -= 1900;

        if(wday == "Sun")
        {
            startdate.tm_wday = 0;
        }
        if(wday == "Mon")
        {
            startdate.tm_wday = 1;
        }
        if(wday == "Tue")
        {
            startdate.tm_wday = 2;
        }
        if(wday == "Wed")
        {
            startdate.tm_wday = 3;
        }
        if(wday == "Thu")
        {
            startdate.tm_wday = 4;
        }
        if(wday == "Fri")
        {
            startdate.tm_wday = 5;
        }
        if(wday == "Sat")
        {
            startdate.tm_wday = 6;
        }
        if(wday1 == "Sun")
        {
            enddate.tm_wday = 0;
        }
        if(wday1 == "Mon")
        {
            enddate.tm_wday = 1;
        }
        if(wday1 == "Tue")
        {
            enddate.tm_wday = 2;
        }
        if(wday1 == "Wed")
        {
            enddate.tm_wday = 3;
        }
        if(wday1 == "Thu")
        {
            enddate.tm_wday = 4;
        }
        if(wday1 == "Fri")
        {
            enddate.tm_wday = 5;
        }
        if(wday1 == "Sat")
        {
            enddate.tm_wday = 6;
        }

        if(mon == "Jan")
        {
            startdate.tm_mon = 0;
        }
        if(mon == "Feb")
        {
            startdate.tm_mon = 1;
        }
        if(mon == "Mar")
        {
            startdate.tm_mon = 2;
        }
        if(mon == "Apr")
        {
            startdate.tm_mon = 3;
        }
        if(mon == "May")
        {
            startdate.tm_mon = 4;
        }
        if(mon == "Jun")
        {
            startdate.tm_mon = 5;
        }
        if(mon == "Jul")
        {
            startdate.tm_mon = 6;
        }
        if(mon == "Aug")
        {
            startdate.tm_mon = 7;
        }
        if(mon == "Sep")
        {
            startdate.tm_mon = 8;
        }
        if(mon == "Oct")
        {
            startdate.tm_mon = 9;
        }
        if(mon == "Nov")
        {
            startdate.tm_mon = 10;
        }
        if(mon == "Dec")
        {
            startdate.tm_mon = 11;
        }
        if(mon1 == "Jan")
        {
            enddate.tm_mon = 0;
        }
        if(mon1 == "Feb")
        {
            enddate.tm_mon = 1;
        }
        if(mon1 == "Mar")
        {
            enddate.tm_mon = 2;
        }
        if(mon1 == "Apr")
        {
            enddate.tm_mon = 3;
        }
        if(mon1 == "May")
        {
            enddate.tm_mon = 4;
        }
        if(mon1 == "Jun")
        {
            enddate.tm_mon = 5;
        }
        if(mon1 == "Jul")
        {
            enddate.tm_mon = 6;
        }
        if(mon1 == "Aug")
        {
            enddate.tm_mon = 7;
        }
        if(mon1 == "Sep")
        {
            enddate.tm_mon = 8;
        }
        if(mon1 == "Oct")
        {
            enddate.tm_mon = 9;
        }
        if(mon1 == "Nov")
        {
            enddate.tm_mon = 10;
        }
        if(mon1 == "Dec")
        {
            enddate.tm_mon = 11;
        }

        getline(fin, startCode);
        getline(fin, endCode);
        getline(fin, status);

        fin >> pilotID;
        fin.ignore();

        fin >> copilotID;
        fin.ignore();

        fin >> crew1;
        fin.ignore();

        fin >> crew2;
        fin.ignore();

        fin >> crew3;
        fin.ignore();

        fin >> numCattle;
        fin.ignore();

        startdate.tm_sec = 00;
        enddate.tm_sec = 00;

        temp = new flight(tailnum, startdate, enddate, startCode, endCode, status, pilotID, copilotID, crew1, crew2, crew3, numCattle);
        flightList.push_back(temp);
    }

    fin.close();
}

/*

Function : Check Status
Parameters : None
Return : Nothing, void function.
Description : 
 - Checks to see if flights have landed
 - If they have, it deletes them

*/

void flights::checkStatus()
{
    int deleteCount = 0;

    time_t timer;
    timer = time(NULL);
    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        tm temp = flightList[i] -> getEndTime();
        tm *temp2 = localtime(&timer);
        if(temp.tm_year <= temp2 -> tm_year)
        {
            if(temp.tm_mon <= temp2 -> tm_mon)
            {
                if(temp.tm_mday <= temp2 -> tm_mday)
                {
                    if(temp.tm_hour <= temp2 -> tm_hour)
                    {
                        if(temp.tm_min <= temp2 -> tm_min)
                        {
                            if(temp.tm_sec < temp2 -> tm_sec)
                            {
                                flightList[i] -> setStatus("Completed");
                            }
                        }
                    }
                }
            }
        }
    }

    for(unsigned int i = 0; i < flightList.size(); i++)
    {
        tm temp = flightList[i] -> getEndTime();
        tm *temp2 = localtime(&timer);
        if(temp.tm_year <= temp2 -> tm_year)
        {
            if(temp.tm_mon <= temp2 -> tm_mon)
            {
                if(temp.tm_mday <= temp2 -> tm_mday)
                {
                    if(temp.tm_hour <= temp2 -> tm_hour + 1)
                    {
                        deleteCount++;
                    }
                }
            }
        }
    }

    if(deleteCount > 0)
    {
        cout << "This is a routine deletion of completed flights." << endl;
        if (deleteCount == 1)
        {
            cout << "One Flight has been deleted and is printed below:" << endl << endl;
        }
        else
        {
            cout << deleteCount << " Flights have been deleted and are printed below:" << endl << endl;
        }
        for(unsigned int i = 0; i < flightList.size(); i++)
        {
            tm temp = flightList[i] -> getEndTime();
            tm *temp2 = localtime(&timer);
            if(temp.tm_year <= temp2 -> tm_year)
            {
                if(temp.tm_mon <= temp2 -> tm_mon)
                {
                    if(temp.tm_mday <= temp2 -> tm_mday)
                    {
                        if(temp.tm_hour <= temp2 -> tm_hour + 1)
                        {
                            cout << "Tail Number: " << flightList[i] -> getTailNum()   << endl;
                            cout << "Start Date: "  << flightList[i] -> getStartDate() << endl << endl; 
                            flightList.erase(flightList.begin() + i);
                            flightCount--;
                            save();
                        }
                    }
                }
            }
        }
    }
}

//Returns flight count

int flights::getFlightCount()
{
    return flightCount;
}