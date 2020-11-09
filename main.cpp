#include <iostream>
#include <vector>
#include <string>

#include "crewMembers.h"
#include "flights.h"
#include "aircrafts.h"

using namespace std;

void header();

int main ()
{
    header();

    cout << "Howdy" << endl;

    crewMembers crew;
    aircrafts aircraft;
    flights flight;

    int choice;

    //Menu goes here

    do
    {
        //Unedited

        cout << "0. Exit" << endl;
        cout << "1. Crew Member Menu" << endl;
        cout << "2. Aircraft Menu"    << endl;
        cout << "3. Flight Menu"      << endl;
        cout << "Enter your choice(0-3): ";
        cin >> choice;

        //Flushing the input stream
        cin.ignore();

        cout << endl;

        if(choice == 0)
        {
            cout << "Thank you for navigating the menu." << endl;
        }
        
        //Mild error handling
        
        if(choice < 0 || choice > 3)
        {
            cout << "You did not enter a possible choice..." << endl;
        }
    
       //Switch statement to run the function of the choice the user made
    
       switch(choice)
       {
           case 1:  crew.menu();        break;
           case 2:  aircraft.menu();    break;
           case 3:  flight.menu(&crew, &aircraft); break;
       }

    }while(choice != 0);


    return 0;
}

/*
======================================================================================================================================
Function : Header
Parameters : None
Return : Nothing, void function.
Description : This function places a header wherever called.
======================================================================================================================================
*/
 
void header()
{
    cout << "+- - - - - - - - - - - - - - - - - - - - - - - +\n";
    cout << "|       Computer Science and Engineering       |\n";
    cout << "|        CSCE 1040 - Computer Science 2        |\n";
    cout << "|   Read Ballew rlb0422 readballew@my.unt.edu  |\n";
    cout << "+- - - - - - - - - - - - - - - - - - - - - - - +\n";
      
    return;
}