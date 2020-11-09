#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "aircrafts.h"

/*

Function : Print Menu
Parameters : None
Return : Nothing, void function.
Description : Prints secondary menu of options for aircrafts

*/

void aircrafts::menu()
{
    int choice;

    

    do
    { 
        if(aircraftCount == 0)
        {
            load();
        }

        cout << "Aircraft Menu" << endl << endl;

        cout << "0. Exit to Main Menu"   << endl;
        cout << "1. Add a Aircraft"      << endl;
        cout << "2. Edit a Aircraft"     << endl;
        cout << "3. Delete a Aircraft"   << endl;
        cout << "4. Print One Aircraft"  << endl;
        cout << "5. Print All Aircrafts" << endl;
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
            case 1: add();           break;
            case 2: edit();          break;
            case 3: decimate();      break;
            case 4: printDetails();  break;
            case 5: printAll();      break;
       }

    }while(choice != 0);

}

/*

Function : Add an Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - 

*/

void aircrafts::add()
{
    aircraft *temp;

    string make, model, tailnum, range, status;
    int seats, choice;

    cout << "Enter make: ";
    getline(cin, make);

    cout << "Enter model: ";
    getline(cin, model);

    cout << "Enter tail number: ";
    getline(cin, tailnum);

    cout << "Enter range: ";
    getline(cin, range);

    cout << "Enter status: " << endl;
    cout << "(1) Available"  << endl;
    cout << "(2) On Flight"  << endl;
    cout << "(3) Broken"     << endl;
    cout << "Option(1-3): ";
    cin >> choice;
    cin.ignore();

    do
    {
        
        //Mild error handling
        
        if(choice < 1 || choice > 3)
        {
            cout << "You did not enter a possible choice..." << endl;
            cout << "Option(1-3): ";
            cin >> choice;
            cin.ignore();
        }
    
    }while (choice < 1 || choice > 3);

    //Switch statement to run the function of the choice the user made
    
    switch(choice)
    {
        case 1:  status = "Available";   break;
        case 2:  status = "On Flight";   break;
        case 3:  status = "Broken";      break;
    }

    cout << "Enter number of seats: ";
    cin >> seats;
    cin.ignore();

    temp = new aircraft(make, model, tailnum, range, status, seats);
    
    aircraftList.push_back(temp);
    aircraftCount++;

    somethingSpecial();

    cout << "Aircraft added!" << endl << endl;
}

/*

Function : Edit an Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Edits an aircraft specified by a user

*/

void aircrafts::edit()
{
    if (aircraftList.size() == 0)
    {
        cout << "There are no aircraft to edit." << endl;
        return;
    }

    string tailnum, range;
    int found, choice, seats;

    do
    {
        cout << "Enter the tail number of the aircraft you wish to edit:" << endl;
        getline(cin, tailnum);

        found = search(tailnum);

        if(search(tailnum) == -1)
        {
            cout << "Tail number not found" << endl;
        }

    }while(search(tailnum) == -1);

    cout << "What part of aircraft "<< aircraftList[found] -> getTailNum() << " do you want to change?" << endl;

    do
    {
        cout << "(0) Exit Edit Menu" << endl;
        cout << "(1) Seats"          << endl;
        cout << "(2) Range"          << endl;
        cout << "(3) Status"         << endl;
        cout << "Option(0-3): ";
        cin >> choice;
        cin.ignore();

        do
        {
            //Mild error handling
            if(choice < 0 || choice > 3)
            {
                cout << "You did not enter a possible choice..." << endl;
                cout << "Option(0-3): ";
                cin >> choice;
                cin.ignore();
            }
        
        }while (choice < 0 || choice > 3);

        switch(choice)
        {
            case 1:
                cout << "Enter the new number of seats for aircraft " << aircraftList[found] -> getTailNum() <<   ": ";
                cin >> seats;
                aircraftList[found] -> setNumSeats(seats);
                break;

            case 2:
                cout << "Enter the new range for aircraft " << aircraftList[found] -> getTailNum() << ": ";
                getline(cin, range);
                aircraftList[found] -> setRange(range);
                break;

            case 3:
                cout << "Enter status: " << endl;
                cout << "(1) Available"   << endl;
                cout << "(2) On Flight" << endl;
                cout << "(3) Broken"    << endl;
                cout << "Option(1-3): ";
                cin >> choice;
                cin.ignore();

                do
                {
        
                    //Mild error handling
        
                    if(choice < 1 || choice > 3)
                    {
                        cout << "You did not enter a possible choice..." << endl;
                        cout << "Option(1-3): ";
                        cin >> choice;
                        cin.ignore();
                    }
    
                }while (choice < 1 || choice > 3);

                //Switch statement to run the function of the choice the user made
    
                switch(choice)
                {
                    case 1: aircraftList[found] -> setStatus("Available"); break;
                    case 2: aircraftList[found] -> setStatus("On Flight"); break;
                    case 3: aircraftList[found] -> setStatus("Broken"); break;
                }
                break;
        }
    }while(choice != 0);
}

/*

Function : Delete an Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Deletes an aircraft specified by a user

*/

void aircrafts::decimate()
{
    if (aircraftList.size() == 0)
    {
        cout << "There is no aircraft to delete." << endl;
        return;
    }

    string tailnum;
    int found;

    do
    {
        cout << "Enter the tail number: ";
        getline(cin, tailnum);

        found = search(tailnum);

        if(search(tailnum) == -1)
        {
            cout << "Tail number not found." << endl;
        }

    }while(search(tailnum) == -1);

    aircraftList.erase(aircraftList.begin() + found);

    aircraftCount--;
    save();
}

/*

Function : Search Aircrafts
Parameters : String x - passed a value to search for a matching instance of an object
Return : Nothing, void function.
Description : 
 - Basic search function passed a string to look for a matching instance of an object

*/

int aircrafts::search(string x)
{ 
    for(unsigned int i = 0; i < aircraftList.size(); i++)
    {
        if(aircraftList[i] -> getTailNum() == x)
        {
            return i;
        }
    }

    return -1;

}

/*

Function : Print All Aircrafts
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints all aircrafts

*/

void aircrafts::printAll()
{
    if (aircraftList.size() == 0)
    {
        cout << "There are no aircrafts to print." << endl;
        return;
    }

    for(unsigned int i = 0; i < aircraftList.size(); i++)
    {
        cout << "Aircraft Make: "         << aircraftList[i] -> getMake()    << endl;
        cout << "Aircraft Model: "        << aircraftList[i] -> getModel()   << endl;
        cout << "Aircraft Tail Number: "  << aircraftList[i] -> getTailNum() << endl;
        cout << "Aircraft Range: "        << aircraftList[i] -> getRange()   << endl;
        cout << "Aircraft Status: "       << aircraftList[i] -> getStatus()  << endl << endl;
    }
}

/*

Function : Print One Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints an aircraft specified by a user

*/

void aircrafts::printDetails()
{
    if (aircraftList.size() == 0)
    {
        cout << "There is no aircraft to print." << endl;
        return;
    }

    string tailnum;
    int found;

    do
    {
        cout << "Enter the tail number: ";
        getline(cin, tailnum);

        found = search(tailnum);

        if(search(tailnum) == -1)
        {
            cout << "Tail number not found." << endl;
        }

    }while(search(tailnum) == -1);

    cout << "Aircraft Make: "         << aircraftList[found] -> getMake()    << endl;
    cout << "Aircraft Model: "        << aircraftList[found] -> getModel()   << endl;
    cout << "Aircraft Tail Number: "  << aircraftList[found] -> getTailNum() << endl;
    cout << "Aircraft Range: "        << aircraftList[found] -> getRange()   << endl;
    cout << "Aircraft Status: "       << aircraftList[found] -> getStatus()  << endl;

}

/*

Function : Save Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Saves all aircraft in existence to a file

*/

void aircrafts::save()
{
    ofstream fout;

    fout.open("aircraft.txt");

    fout << aircraftCount << endl;

    for(int i = 0; i < aircraftCount; i++)
    {
        fout << aircraftList[i] -> getMake()     << endl;
        fout << aircraftList[i] -> getModel()    << endl;
        fout << aircraftList[i] -> getTailNum()  << endl;
        fout << aircraftList[i] -> getRange()    << endl;
        fout << aircraftList[i] -> getStatus()   << endl;
        fout << aircraftList[i] -> getNumSeats() << endl;
    }

    fout.close();
}

/*

Function : Load Aircraft
Parameters : None
Return : Nothing, void function.
Description : 
 - Loads all saved aircraft from a file

*/

void aircrafts::load()
{
    string make, model, tailnum, range, status;
    int numSeats = 0;
    aircraft *temp;

    ifstream fin;

    fin.open("aircraft.txt");
    if(fin.fail())
    {
        cout << "No Aircraft load file found or loaded." << endl << endl;
        return;
    }
    else
    {
        cout << "Aircraft Load file found and loaded." << endl << endl;
    }

    fin >> aircraftCount;
    fin.ignore();

    for(int i = 0; i < aircraftCount; i++)
    {
        getline(fin, make);
        getline(fin, model);
        getline(fin, tailnum);
        getline(fin, range);
        getline(fin, status);
        fin >> numSeats;
        fin.ignore();

        temp = new aircraft(make, model, tailnum, range, status, numSeats);
        aircraftList.push_back(temp);
    }

    fin.close();
}

//Returns seat count of a flight

int aircrafts::getSeats(int x)
{
    int y;
    y = aircraftList[x] -> getNumSeats();
    return y;
}

//Something Special
void aircrafts::somethingSpecial()
{
    ofstream fout;
    fout.open("randomThing.txt");

    fout << aircraftList.size() << endl;

    for(unsigned int i = 0; i < aircraftList.size(); i++)
    {
        fout << aircraftList[i] -> getTailNum() << endl;
    }

    fout.close();
}
/*
int aircrafts::passengerCheckerino(int lilTimmyDropCattle)
{
    for(unsigned int i = 0; i < aircraftList.size(); i++)
    {
        if(aircraftList[i] -> getNumSeats() < lilTimmyDropCattle)
        {
            return -1;
        }
    }

    return 1;
}
*/

int aircrafts::passengerCheckerino(int lilTimmyDropCattle, string tail)
{
    int found = search(tail);
    while(found == -1)
    {
        cout << "No tail found, re-enter:";
        getline(cin, tail);
        found = search(tail);
    }
    if(lilTimmyDropCattle > aircraftList[found] -> getNumSeats())
    {
        return -1;
    }
    
    return 1;
}

//Returns aircraft count

int aircrafts::getAircraftCount()
{
    return aircraftCount;
}
