/*
    Author: Leonardo Vallejos
    Date: January 29, 2017
    FileName: main.cpp
    Purpose: This program simulates a simple contact manager application.
    Input: 
        1. The program inputs from the user 10 people's names and their telephone numbers.
        2. To search, the program asks for a name to search for.
    Output: 
        1. The program will print the list of users and their telephone numbers sorted by phone number.
        2. If found, the program prints the name and the associated telephone number for that person.
           If the contact is not found, the program will print that the user cannot be found.
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int maxContacts = 10; // max contacts
    string names[maxContacts];
    int phones[maxContacts];
    int i = -1;
    int tempPhone = -1;
    string tempName = "";
    string tempPhoneInput = "";
    string searchName = "";
    bool found = false;

    // ask for data
    for (i=0; i<maxContacts; i++) {
        // ask for name
        cout << "Enter Name: " << endl << "> ";
        getline(cin, names[i]);
        
        // ask for phone number
        cout << "Enter Phone: " << endl << "> ";
        getline(cin, tempPhoneInput);
        phones[i] = stoi(tempPhoneInput);
    }

    // sort using bubble sort
    for (i=0; i<maxContacts; i++) {
        if (phones[i] > phones[i + 1]) {
            // swap phones
            tempPhone = phones[i];
            phones[i] = phones[i + 1];
            phones[i + 1] = tempPhone;

            // swap names
            tempName = names[i];
            names[i] = names[i + 1];
            names[i + 1] = tempName;
        }
    }
    
    // print data
    cout << endl << "Sorted Contact List:" << endl << "-----------------------------" << endl;
    cout << "Phone\t\tName" << endl << "-----------------------------" << endl;
    for (i=0; i<maxContacts; i++) {
        cout << phones[i] << "\t\t" << names[i] << endl;
    }
    cout << "-----------------------------" << endl;
   
    // ask for contact to search for
    cout << endl << "Enter contact Name:" << endl << "> ";
    getline(cin, searchName);

    // search for contact
    i=0;
    while (!found && i<maxContacts) {
        if (searchName == names[i]) {
            found = true;
        } else {
            i++;
        }
    }
    
    // display search results
    if (found) {
        cout << "Contact found: " << endl << "-----------------------------" << endl;;
        cout << "Phone\t\tName" << endl << "-----------------------------" << endl;
        cout << phones[i] << "\t\t" << names[i] << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "Contact not found: " << searchName << endl;
    }    
    
    return 0;
}

