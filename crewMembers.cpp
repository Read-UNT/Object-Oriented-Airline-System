#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "crewMembers.h"
#include "pilot.h"
#include "copilot.h"
#include "LilTimmyDropTable.h"


using namespace std;

/*

Function : Print Menu
Parameters : None
Return : Nothing, void function.
Description : Prints secondary menu of options for crewmembers

*/

void crewMembers::menu()
{
    int choice;

    do
    {
        if(crewCount == 0)
        {
            load();
        }

        cout << "Crewmember Menu" << endl << endl;

        cout << "0. Exit to Main Menu"     << endl;
        cout << "1. Add a Crewmember"      << endl;
        cout << "2. Edit a Crewmember"     << endl;
        cout << "3. Delete a Crewmember"   << endl;
        cout << "4. Print One Crewmember"  << endl;
        cout << "5. Print All Crewmembers" << endl;
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

Function : Add a New Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Adds a new crew member
*/

void crewMembers::add()
{
    crewMember *temp;

    string name, type, status, rating, position;
    int id, choice, choice1;
    double hours;

    //Name

    cout << "Enter name: ";
    getline(cin, name);

    //Status

    cout << "Enter status"  << endl;
    cout << "(1) Available" << endl;
    cout << "(2) Vacation"  << endl;
    cout << "(3) Out Sick"  << endl;
    cout << "Option(1-3): ";
    cin >> choice1;

    do
    {
        cin.ignore();
        
        //Mild error handling
        
        if(choice1 < 1 || choice1 > 3)
        {
            cout << "You did not enter a possible choice..." << endl;
            cout << "Option(1-3): ";
            cin >> choice1;
            cin.ignore();
        }

    }while (choice1 < 1 || choice1 > 3);

    //Switch statement to run the function of the choice the user made
    
    switch(choice1)
    {
        case 1:  status = "Available";   break;
        case 2:  status = "On Vacation"; break;
        case 3:  status = "Out Sick";    break;
    }

    //ID

    do
    {
        cout << "Enter 5 digit ID: ";
        cin >> id;
        cin.ignore();

        if(id < 0 || id > 100000)
        {
            cout << "ID out of range." << endl;
        }

    }while(id < 0 || id > 100000);

    //Type

    cout << "Enter type"  << endl;
    cout << "(1) Pilot"   << endl;
    cout << "(2) CoPilot" << endl;
    cout << "(3) Crew"    << endl;
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

    switch(choice)
    {
        case 1:  
            type = "Pilot";
             
            cout << "Enter the rating of the Pilot: ";
            getline(cin, rating);
            cout << "Enter the hours flown: ";
            cin >> hours;
            cin.ignore();

            temp = new pilot(name, type, status, id, rating, hours);
            crewList.push_back(temp);

            crewCount++;
            cout << "Pilot added!" << endl << endl;
            break;

        case 2:  
            type = "CoPilot";

            cout << "Enter the rating of the Copilot: ";
            getline(cin, rating);
            cout << "Enter the hours flown: ";
            cin >> hours;
            cin.ignore();

            temp = new copilot(name, type, status, id, rating, hours);
            crewList.push_back(temp);

            crewCount++;
            cout << "Copilot added!" << endl << endl;
            break;

        case 3:  
            type = "Crew";

            cout << "Enter the position: " << endl;
            cout << "(1) First Class"      << endl;
            cout << "(2) Business Class"   << endl;
            cout << "(3) Economy Front"    << endl;
            cout << "(4) Economy Rear"     << endl;
            cout << "(5) Lead"             << endl;
            cout << "Option(1-5): ";
            cin >> choice;
            cin.ignore();

            switch(choice)
            {
                case 1:  position = "First Class";    break;
                case 2:  position = "Business Class"; break;
                case 3:  position = "Economy Front";  break;
                case 4:  position = "Economy Rear";   break;
                case 5:  position = "Lead";           break;
            }

            do
            {
                //Mild error handling
                if(choice < 1 || choice > 5)
                {
                    cout << "You did not enter a possible choice..." << endl;
                    cout << "Option(1-5): ";
                    cin >> choice;
                    cin.ignore();
                }
    
            }while (choice < 1 || choice > 5);

            temp = new liltimmydroptable(name, type, status, id, position);
            crewList.push_back(temp);

            crewCount++;
            cout << position << " Crew added!" << endl << endl;
            break;
    }

    somethingSpecial();
}

/*

Function : Edit Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Edits a specified crew member

*/

void crewMembers::edit()
{
    double hoursFlown;
    string position, rating;

    if(crewList.size() == 0)
    {
        cout << "There are no crewmembers to edit." << endl;
        return;
    }

    int id, found, choice, choice1, choice2, param = 3;
    string name, status, type;

    do
    {
        cout << "Enter the ID: ";
        cin >> id;

        found = search(id);

        if(search(id) == -1)
        {
            cout << "ID not found" << endl;
        }

    }while(search(id) == -1);

    cout << "What part of Crewmember ID "<< crewList[found] -> getID() << " do you want to change?" << endl;

    do
    {
        cout << "(0) Exit Edit Menu" << endl;
        cout << "(1) Name"           << endl;
        cout << "(2) Status"         << endl;
        cout << "(3) Type"           << endl;

        if(crewList[found] -> getType() == "Pilot" || crewList[found] -> getType() == "CoPilot")
        {
            cout << "(4) Rating"         << endl;
            cout << "(5) Hours Flown"    << endl;
            cout << "Option(0-5): ";
            param = 5;
        }
        else
        {
            cout << "(4) Cabin Position" << endl;
            cout << "Option(0-4): ";
            param = 4;
        }

        cin >> choice;
        cin.ignore();

        //Mild error handling
        while(choice < 0 || choice > param)
        {
            cout << "You did not enter a possible choice..." << endl;
            cout << "Option(0-"<< param << "): ";
            cin >> choice;
            cin.ignore();
        }
        
        switch(choice)
        {
            case 1:  
                cout << "Enter name: ";
                getline(cin, name);
                crewList[found] -> setName(name);
                break;

            case 2:  
                cout << "Enter status"  << endl;
                cout << "(1) Available" << endl;
                cout << "(2) Vacation"  << endl;
                cout << "(3) Out Sick"  << endl;
                cout << "Option(1-3): ";
                cin >> choice1;
                cin.ignore();
            
                //cin.ignore();
                
                //Mild error handling
                
                while (choice1 < 1 || choice1 > 3);
                {
                        cout << "You did not enter a possible choice..." << endl;
                        cout << "Option(1-3): ";
                        cin >> choice1;
                        cin.ignore();
                }    
        
                //Switch statement to run the function of the choice the user made
            
                switch(choice1)
                {
                    case 1:  status = "Available";   break;
                    case 2:  status = "On Vacation"; break;
                    case 3:  status = "Out Sick";    break;
                }

                crewList[found] -> setStatus(status);
                break;

            case 3:  
                cout << "Enter type"  << endl;
                cout << "(1) Pilot"   << endl;
                cout << "(2) CoPilot" << endl;
                cout << "(3) Crew"    << endl;
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
                    case 1:  

                        type = "Pilot";   
                        break;

                    case 2:  

                        type = "CoPilot"; 
                        break;

                    case 3:

                        type = "Crew";    
                        break;
                }

                crewList[found] -> setType(type);
                break;

            case 4:
                if(crewList[found] -> getType() == "Pilot" || crewList[found] -> getType() == "Copilot")
                {
                    cout << "Enter the new rating: ";
                    getline(cin, rating);
                    crewList[found] -> editRating(rating);
                }
                else
                {
                    cout << "Enter the new position: " << endl;
                    cout << "(1) First Class"      << endl;
                    cout << "(2) Business Class"   << endl;
                    cout << "(3) Economy Front"    << endl;
                    cout << "(4) Economy Rear"     << endl;
                    cout << "(5) Lead"             << endl;
                    cout << "Option(1-5): ";
                    cin >> choice;
                    cin.ignore();

                    switch(choice)
                    {
                        case 1:  position = "First Class";    break;
                        case 2:  position = "Business Class"; break;
                        case 3:  position = "Economy Front";  break;
                        case 4:  position = "Economy Rear";   break;
                        case 5:  position = "Lead";           break;
                    }

                    do
                    {
                        //Mild error handling
                        if(choice < 1 || choice > 5)
                        {
                            cout << "You did not enter a possible choice..." << endl;
                            cout << "Option(1-5): ";
                            cin >> choice;
                            cin.ignore();
                        }
    
                    }while (choice < 1 || choice > 5);

                    crewList[found] -> editPosition(position);
                }
                break;


            case 5:
                cout << "Enter the new number of hours flown: ";
                cin >> hoursFlown;
                cin.ignore();
                crewList[found] -> editHoursFlown(hoursFlown);
                break;
        }

    }while(choice != 0);
}

/*

Function : Delete Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Deletes a specified crew member

*/

void crewMembers::decimate()
{
    if(crewList.size() == 0)
    {
        cout << "There are no crewmembers to delete." << endl;
        return;
    }

    int found, id;

    do
    {
        cout << "Enter the ID: ";
        cin >> id;

        found = search(id);

        if(search(id) == -1)
        {
            cout << "ID not found." << endl;
        }

    }while(search(id) == -1);

    crewList.erase(crewList.begin() + found);
    crewCount--;

    save();
}

/*

Function : Search Crew Members
Parameters : None
Return : Nothing, void function.
Description : 
 - Finds a function derived from specifications by the user

*/

int crewMembers::search(int x)
{
    for(unsigned int i = 0; i < crewList.size(); i++)
    {
        if(crewList[i] -> getID() == x)
        {
            return i;
        }
    }

    return -1;
}

/*

Function : Print All Crew Members
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints all existing functions

*/

void crewMembers::printAll()
{
    if(crewList.size() == 0)
    {
        cout << "There are no crewmembers to print." << endl;
        return;
    }

    for(unsigned int i = 0; i < crewList.size(); i++)
    {
        crewList[i] -> liltimmydroptablePRINT();
    }

}

/*

Function : Print One Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Prints an existing function that match specifications by the user 


*/

void crewMembers::printDetails()
{
    if(crewList.size() == 0)
    {
        cout << "There are no crewmembers to print." << endl;
        return;
    }

    int id, found;

    do
    {
        cout << "Enter the ID: ";
        cin >> id;

        found = search(id);

        if(search(id) == -1)
        {
            cout << "ID not found" << endl;
        }

    }while(search(id) == -1);
    
    crewList[found] -> liltimmydroptablePRINT();

}

/*

Function : Save Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Saves all crew members and their info to a file automatically

*/

void crewMembers::save()
{
    string type;
    int choice;

    ofstream fout;

    fout.open("crew.txt");

    fout << crewCount << endl;

    fout.close();

    for(int i = 0; i < crewCount; i++)
    {
        fout.open("crew.txt", ofstream::app);

        fout << crewList[i] -> getName()   << endl;
        fout << crewList[i] -> getType()   << endl;
        fout << crewList[i] -> getStatus() << endl;
        fout << crewList[i] -> getID()     << endl;

        fout.close();

        crewList[i] -> saving();
    }
}

/*

Function : Load Crew Member
Parameters : None
Return : Nothing, void function.
Description : 
 - Loads crew members from a file automatically

*/

void crewMembers::load()
{
    string name, type, status, rating, position;
    int id = 0, choice = 0, tempCount = 0;
    double hours;
    crewMember *temp;

    ifstream fin;

    fin.open("crew.txt");
    if(fin.fail())
    {
        cout << "No Crew load file found or loaded." << endl << endl;
        return;
    }
    else
    {
        cout << "Crew Load file found and loaded." << endl << endl;
    }

    fin >> tempCount;
    fin.ignore();

    crewCount = tempCount;

    for(int i = 0; i < crewCount; i++)
    {
        getline(fin, name);
        getline(fin, type);
        getline(fin, status);
        fin >> id;
        fin.ignore();

        if(type == "Pilot")
        {
            cout << "Detected Pilot" << endl;
            getline(fin, rating);
            fin >> hours;
            fin.ignore();
            temp = new pilot(name, type, status, id, rating, hours);
            crewList.push_back(temp);
        }
        if(type == "CoPilot")
        {
            cout << "Detected CoPilot" << endl;
            getline(fin, rating);
            fin >> hours;
            fin.ignore();
            temp = new copilot(name, type, status, id, rating, hours);
            crewList.push_back(temp);
        }
        if(type == "Crew")
        {
            cout << "Detected Crew" << endl;
            getline(fin, position);
            temp = new liltimmydroptable(name, type, status, id, position);
            crewList.push_back(temp);
        }
    }

    fin.close();
}

//Something Special

void crewMembers::somethingSpecial()
{
    ofstream fout;
    fout.open("cattle.txt");

    fout << crewList.size() << endl;

    for(unsigned int i = 0; i < crewList.size(); i++)
    {
        fout << crewList[i] -> getID() << endl;
    }

    fout.close();
}

//Returns crew count

int crewMembers::getCrewCount()
{
    return crewCount;
}