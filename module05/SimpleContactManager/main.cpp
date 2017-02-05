/*
    Author: Leonardo Vallejos
    Date: February 4, 2017
    FileName: main.cpp
    Purpose: This program simulates a simple contact manager application.
    Input: 
        1. The program will call the appropriate function based on user choice and the program will return to the menu afterwards.
        2. The program inputs the name and phone for up to 10 contacts.
        3. To search, the program asks for a name to search for.
    Output: 
        1. The program loops through a menu until the user selects the option to quit
        2. The program will list the contacts in the proper order
        3. When searching for a contact, the program shows the contact information if found
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * Adds a new contact to the list
 * @param phones
 * @param names
 * @param position
 */
void addContact(int *phones, string *names, int &position) {
    string tempPhoneInput = "";

    // ask for name
    cout << "Enter Name: ";
    getline(cin, names[position]);

    // ask for phone number
    cout << "Enter Phone: ";
    getline(cin, tempPhoneInput);
    phones[position] = stoi(tempPhoneInput);
    
    position++;
}

/**
 * Sorts contact list using bubble sort algorithm in ascending order
 * @param sortAsc
 * @param phones
 * @param names
 * @param position
 */
void sortContactsList(bool sortAsc, int *phones, string *names, int position) {
    int i, j, flag = 1;
    int tempPhone = -1;
    string tempName = "";

    // sort using bubble sort
    for(i = 1; (i < position) && flag; i++) {
        flag = 0;
        for (j=0; j < (position - 1); j++) {
            if (sortAsc) {
                // ascending order
                if (phones[j+1] < phones[j]) {
                    // swap phones
                    tempPhone = phones[j];
                    phones[j] = phones[j+1];
                    phones[j+1] = tempPhone;

                    // swap names
                    tempName = names[j];
                    names[j] = names[j+1];
                    names[j+1] = tempName;

                    flag = 1;               // indicates that a swap occurred
                } // if
            } else {
                // descending order
                if (phones[j+1] > phones[j]) {
                    // swap phones
                    tempPhone = phones[j];
                    phones[j] = phones[j+1];
                    phones[j+1] = tempPhone;

                    // swap names
                    tempName = names[j];
                    names[j] = names[j+1];
                    names[j+1] = tempName;

                    flag = 1;               // indicates that a swap occurred
                } // if
            } // else
        } // for
    } // for
}

/**
 * Print contact list
 * @param phones
 * @param names
 * @param position
 */
void printContactsList(int phones[], string names[], int position) {
    // print data
    if (position > 0) {
        cout << "-----------------------------" << endl;
        cout << "Phone\t\tName" << endl;
        cout << "-----------------------------" << endl;
        for (int i=0; i<position; i++) {
            cout << phones[i] << "\t\t" << names[i] << endl;
        }
        cout << "-----------------------------" << endl;
    } else {
        cout << "No contacts added yet." << endl;
    }
}

/**
 * Search a contact
 * @param searchName
 * @param names
 * @param position
 * @return 
 */
int searchContact(string searchName, string names[], int position) {
    int found = -1;
    int i = 0;
    
    // search for contact
    while (found < 0 && i < position) {
        if (searchName == names[i]) {
            found = i;
        } else {
            i++;
        }
    }

    return found;
}

/**
 * Prints the Menu
 */
void printMenu() {
    cout << "----------------------" << endl;
    cout << "       - MENU -" << endl;
    cout << "----------------------" << endl;
    cout << "1. Add new contact" << endl;
    cout << "2. Sort ascending" << endl;
    cout << "3. Sort descending" << endl;
    cout << "4. Print list" << endl;
    cout << "5. Search contact" << endl;
    cout << "6. End program" << endl;
    cout << "> ";
}

/**
 * main function
 */
int main(int argc, char** argv) {
    const int maxContacts = 10; // max contacts
    string names[maxContacts]; // contact array for names
    int phones[maxContacts]; // contact array for phones
    int position = 0; // last position with data in the arrays
    bool endProgram = false; // flag to loop through the menu
    int menuOption = 0; // selected menu option
    int foundAt = -1; // position where element was found in the array
    string searchName = ""; // name to search for

    // main program loop
    while (!endProgram) {
        printMenu();
        cin >> menuOption;
        
        cin.ignore(); // clean buffer
        
        switch (menuOption) {
            case 1:
                // add new contact
                if (position < maxContacts) {
                    addContact(phones, names, position);
                    cout << "Contact added!" << endl;
                } else {
                    cout << "Error: Cannot add more contacts." << endl;
                }
                break;

            case 2:
                // sort array in ascending order
                sortContactsList(true, phones, names, position);
                cout << "Done" << endl;
                break;

            case 3:
                // sort array in descending order
                sortContactsList(false, phones, names, position);
                cout << "Done" << endl;
                break;

            case 4:
                // prints all the contacts information
                printContactsList(phones, names, position);
                break;

            case 5:
                // search for a contact by name
                cout << endl << "Enter contact Name: ";
                // ask for contact to search for
                getline(std::cin, searchName);

                foundAt = searchContact(searchName, names, position);
                
                // display search results
                if (foundAt >= 0) {
                    cout << "Contact found: " << endl << "-----------------------------" << endl;;
                    cout << "Phone\t\tName" << endl << "-----------------------------" << endl;
                    cout << phones[foundAt] << "\t\t" << names[foundAt] << endl;
                    cout << "-----------------------------" << endl;
                } else {
                    cout << "Contact not found: " << searchName << endl;
                }    
                
                break;

            case 6:
                // ends the program and quit
                endProgram = true;
                break;

            default:
                // unknown option
                cout << "Error: Incorrect menu option. Please try again." << endl;
        }
    }

    cout << "Good Bye!" << endl;

    return 0;
}
