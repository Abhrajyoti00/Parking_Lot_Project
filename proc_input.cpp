/* 

proc_input.cpp --> this is driver program for Parking Lot
It contains the main() function and operates on the backend logic defined in parking_lot.cpp

* Used with file file_inputs.txt or interactively

Created By: Abhrajyoti Kundu
Date: 23 Dec 2020

*/ 

//#include <bits/stdc++.h>
#include <iostream>
#include <string>   
#include <vector>
#include <sstream>  // for stringstream
#include <fstream> // for file handling
#include "parking_lot.cpp"

using namespace std;

ParkingLot parking_lot;

void process(string command_params)
{

    vector<string> command;
    string word;                      // word variable to store word
    stringstream iss(command_params); // making a string stream

    while (iss >> word) // Read each word and insert it into a vector 'command'
        command.push_back(word);

    // for(int i=0; i<command.size(); i++)
    //     cout<<"Command ["<<i<<"] is: "<<command[i]<<endl;


    if (command[0] == "create_parking_lot")
    {
        if (command.size() != 2)
        {
            cout << "create_parking_lot needs no of slots as well" << endl;
        }        
        else if (isdigit(command[1][0]) == 0)
        {
            cout << "param should be 'integer type'" << endl;
        }
        else
        {
            parking_lot.create_parking_lot(stoi(command[1]));
        }
    }

    else if (command[0] == "park")
    {
        if (command.size() != 3)
        {
            cout << "park needs registration number and color as well" << endl;
        }

        else
        {
            Car car(command[1], command[2]);
            parking_lot.park(car);
        }
    }

    else if (command[0] == "leave")
    {
        if (command.size() != 2)
        {
            cout << "leave needs slot number as well" << endl;
        }
        else if (isdigit(char(command[1][0])) == 0)
        {
            cout << "slot number should be 'integer type'" << endl;
        }

        else
        {
            parking_lot.leave(stoi(command[1]));
        }
    }

    else if (command[0] == "status")
        parking_lot.status();

    else if (command[0] == "registration_numbers_for_cars_with_colour")
    {
        if (command.size() != 2)
            cout << "registration_numbers_for_cars_with_colour needs color as well" << endl;
        else
            parking_lot.registration_numbers_for_cars_with_colour(command[1]);
    }

    else if (command[0] == "slot_numbers_for_cars_with_colour")
    {
        if (command.size() != 2)
            cout << "slot_numbers_for_cars_with_colour needs color as well" << endl;
        else
            parking_lot.slot_numbers_for_cars_with_colour(command[1]);
    }

    else if (command[0] == "slot_number_for_registration_number")
    {
        if (command.size() != 2)
            cout << "slot_number_for_registration_number needs registration_number as well" << endl;
        else
            parking_lot.slot_number_for_registration_number(command[1]);
    }

    else if(command[0] == "clear")  // to clear console screen
        system("clear");

    else if (command[0] == "exit")  // to exit from console back to shell
        exit(0);

    else
        cout << "Wrong Command" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    { 
        while (true)
        {
            string line;
            getline(cin, line);
            process(line);
        }
    }
    // else
    //     cout << "Wrong Command!" << endl;

    // *************** File Handling part from here********************
    else
    {
        // We assume argv[1] is a filename to open
        ifstream the_file(argv[1]);

        if (!the_file.is_open())    // check to see if file is open
            cout << "Could not open file" << endl;
        else
        {
            string line;
            while (getline(the_file, line))
            {
                process(line);
            }
        }
    }
    // the_file is closed implicitly here

    return 0;
}
