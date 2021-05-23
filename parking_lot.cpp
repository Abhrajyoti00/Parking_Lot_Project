/* 

parking_lot.cpp --> Parking Lot program containing the logic

Created By: Abhrajyoti Kundu
Date: 23 Dec 2020

*/ 

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>    

using namespace std;

class Car
{

public:
    string registration_number;
    string color;

    Car(string reg_no, string clr)
    {
        registration_number = reg_no;
        color = clr;
    }
};

class ParkingLot
{
    // registration_slot_mapping is a map(ordered by default) that will have key as registration_no(string) and value as slot(int)
    map<string, int> registration_slot_mapping;

    // registration_color_mapping is a map(ordered by default) that will have key as color(string) and value as registration_no(string)
    map<string, string> registration_color_mapping;

    // slot_car_mapping is a map(ordered by default) to maintain the orders of cars while showing status
    // it will have key as slot(int) and value as car(Car object)
    map<int, Car> slot_car_mapping;

    // below is a priority queue to store the available parking lots.
    // Using priority queue as this will always give minimum slot number in O(1) time
    priority_queue<int, vector<int>, greater<int>> available_parking_lots;

public:

    // The below function takes total slots as parameter input and creates a parking lot accordingly
    int flag = 0;
    bool create_parking_lot(int total_slots)
    {    
        if ((total_slots > 0) && (flag != 1))   
        // this check is to handle case when total_slots given is 0 or user trying to create parking when 1 is already existing
        {
            cout << "Created a parking lot with " << total_slots << " slots" << endl;
            flag = 1;
            for (int i = 1; i <= total_slots; i++)
            {
                available_parking_lots.push(i);
            }
            return true;
        }
        else
        {
            cout<< "Not possible to create parking lot" << endl;
            return false;
        }
    }

    // The below function returns the status of the parking lot
    bool status()
    {
        cout << "Slot No. \tRegistration No \tColour " << endl;
        map<int, Car>::iterator itr;
        for (itr = slot_car_mapping.begin(); itr != slot_car_mapping.end(); ++itr)
        {
            cout << "  " << itr->first << "\t\t" << itr->second.registration_number << "\t\t" << itr->second.color << endl;
        }

        //cout << endl;
        return true;
    }

    // The below function returns the nearest available slot
    int get_nearest_slot()
    {
        if (available_parking_lots.size())
        {
            int slot_val; // to store the nearest available slot value
            slot_val = available_parking_lots.top();
            available_parking_lots.pop();
            return slot_val;
        }
        else
            return 0;
    }

    // The below function will take the slot number to be made free
    bool leave(int slot_to_be_freed)
    {
        string found = "";
        for (auto itr : registration_slot_mapping)
        {
            if (itr.second == slot_to_be_freed)
            {
                found = itr.first;
            }
        }

        if (found != "")
        {
            available_parking_lots.push(slot_to_be_freed);
            registration_slot_mapping.erase(found);
            Car car_to_leave = slot_car_mapping.at(slot_to_be_freed);
            car_to_leave.registration_number = found;
            registration_color_mapping[car_to_leave.registration_number] = "";
            slot_car_mapping.erase(slot_to_be_freed);
            cout << "Slot number " << slot_to_be_freed << " is free" << endl;
            return true;
        }

        else
        {
            cout << "Slot is not in use" << endl;
            return false;
        }
    }

    // The below function will park a car in an empty available slot and return the slot number
    // It takes a car object as input
    int park(Car car)
    {
        int slot_no;
        slot_no = get_nearest_slot();
        if (slot_no == 0)
        {
            cout << "Sorry, parking lot is full" << endl;
            return 0;
        }

        cout << "Allocated slot number: " << slot_no << endl;
        slot_car_mapping.insert({slot_no, car});
        registration_slot_mapping.insert({car.registration_number, slot_no});
        registration_color_mapping.insert({car.registration_number, car.color});
        return slot_no;
    }

    // The below function will give the Registration numbers of all cars of a particular colour
    // The color of the car is taken as parameter input
    vector<string> registration_numbers_for_cars_with_colour(string color)
    {
        vector<string> registration_numbers;
        int flag = 0; // added
        for (auto it : registration_color_mapping)
        {
            if (it.second == color)
            {
                flag = 1;
                registration_numbers.push_back(it.first);
            }
        }

        if (flag != 0)
        {
            // cout << "Registration numbers matching the given color are: " << endl;
            for (int i = 0; i < registration_numbers.size() - 1; i++) // running till second-last
            {
                cout << registration_numbers[i] << ", ";
            }
            cout << registration_numbers[registration_numbers.size() - 1] << endl; // printing last stmt separately to avoid ending comma
        }
        else
            cout << "No such cars with color " << color << endl;

        return registration_numbers;
    }

    // The below function will give the Slot numbers of all slots where a car of a particular colour is parked
    // The color of the car is taken as parameter input
    vector<int> slot_numbers_for_cars_with_colour(string color)
    {
        vector<string> registration_numbers;
        int flag = 0;
        for (auto it : registration_color_mapping)
        {
            if ((it.second) == color)
            {
                flag = 1;
                registration_numbers.push_back(it.first);
            }
        }

        vector<int> slots;
        if (flag != 0)
        {
            // vector<int> slots;
            for (int i = 0; i < registration_numbers.size(); i++)
            {
                slots.push_back(registration_slot_mapping[registration_numbers[i]]);
            }

            // cout << "The slot numbers matching the given color are: " << endl;
            for (int i = 0; i < slots.size() - 1; i++) // running till second-last
            {
                cout << slots[i] << ", ";
            }
            cout << slots[slots.size() - 1] << endl; // printing last stmt separately to avoid ending comma
        }

        else
        {
            cout << "No such cars with color " << color << endl;
        }

        return slots;
    }

    // The below function checks for the slot no of the car by taking registration_number as parameter input
    // If no such car found, then displays "Slot not found"
    int slot_number_for_registration_number(string registration_number)
    {
        int slot_number = 0;
        if (auto itr = registration_slot_mapping.find(registration_number); itr != registration_slot_mapping.end())
        {
            slot_number = itr->second; // itr->second gives slot
            cout << slot_number << endl;
            return slot_number;
        }
        else
        {
            cout << "Not found" << endl;    // slot not found
            return slot_number;
        }
    }
};
