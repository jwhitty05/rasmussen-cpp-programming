/*
    Author: Leonardo Vallejos
    Date: February 7, 2017
    FileName: main.cpp
    Purpose: This program simulates a Contact Manager application.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// data structure to store contact information
typedef struct {
    string firstName;
    string lastName;
    int phone;
    string email;
} Contact;

void printMainMenu();
void printSortMenu();
void printSearchMenu();
void printSearchSubMenu();
void addContact(Contact *, int &);
void editContact(Contact *, int);
void bubbleSortAsc(Contact *, int);
void bubbleSortDesc(Contact *, int);
void sortContactsList(bool, Contact *, int);
void printContactsList(Contact *, int);
int searchContactByPhone(int, Contact *, int);
int searchContactByName(int, Contact *, int);
int searchContactByEmail(string, Contact *, int);
void printContact(Contact *, int);
void searchContacts(Contact *, int);
void sortContacts(Contact *, int);
void manageContact(Contact *, int, int);

/**
 * Main function 
 */
int main(int argc, char** argv) {
    const int maxContacts = 5000; // max amount of contacts
    Contact contacts[maxContacts]; // array to store the contacts
    int totalContacts = 0; // current amount of contacts in the list

    int option = -1;
    bool endProgram = false;

    // main program loop
    while (!endProgram) {
        printMainMenu();
        cin >> option;
        
        cin.ignore(); // clean buffer
        
        switch (option) {
            case 1:
                // add
                addContact(contacts, totalContacts);
                break;

            case 2:
                // list
                printContactsList(contacts, totalContacts);
                sortContacts(contacts, totalContacts);
                break;

            case 3:
                // search
                searchContacts(contacts, totalContacts);
                break;

            case 0:
                // end program
                endProgram = true;
                break;

            default:
                cout << "Invalid Option. Try again." << endl;
        }
    }

    cout << "Good Bye!" << endl;
    
    return 0;
}

/**
 * Prints the main menu
 */
void printMainMenu() {
    cout << endl << "-----------------------------" << endl;
    cout << "Main Menu:" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) Add contact" << endl;
    cout << "2) List contacts" << endl;
    cout << "3) Search contacts" << endl;
    cout << "0) Exit program" << endl;
}

/**
 * Prints the sort menu
 */
void printSortMenu() {
    cout << endl << "-----------------------------" << endl;
    cout << "Sort Options:" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) Ascending (by Phone)" << endl;
    cout << "2) Descending (by Phone)" << endl;
    cout << "0) Return to Main Menu" << endl;
}

/**
 * Print search options menu
 */
void printSearchMenu() {
    cout << endl << "-----------------------------" << endl;
    cout << "Search Options:" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) Search by Phone" << endl;
    cout << "2) Search by Name" << endl;
    cout << "3) Search by Email" << endl;
    cout << "0) Return to Main Menu" << endl;
}

/**
 * Print search sub-menu options
 */
void printSearchSubMenu() {
    cout << endl << "-----------------------------" << endl;
    cout << "Options:" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) Edit contact" << endl;
    cout << "0) Return to Main Menu" << endl;
}

/**
 * Adds a new contact
 * @param contacts
 * @param totalContacts
 */
void addContact(Contact *contacts, int &totalContacts) {
    string phone;

    // ask for name
    cout << "Enter First Name: " << endl << "> ";
    getline(cin, contacts[totalContacts].firstName);

    cout << "Enter Last Name: " << endl << "> ";
    getline(cin, contacts[totalContacts].lastName);

    cout << "Enter Phone: " << endl << "> ";
    getline(cin, phone);
    contacts[totalContacts].phone = stoi(phone);

    cout << "Enter Email: " << endl << "> ";
    getline(cin, contacts[totalContacts].email);

    totalContacts++;
}

/**
 * Edits an existing contact
 * @param contacts
 * @param position
 */
void editContact(Contact *contacts, int position) {
    string phone;

    // ask for name
    cout << "Enter First Name (" << contacts[position].firstName << "): " << endl << "> ";
    getline(cin, contacts[position].firstName);

    cout << "Enter Last Name (" << contacts[position].lastName << "): " << endl << "> ";
    getline(cin, contacts[position].lastName);

    cout << "Enter Phone (" << contacts[position].phone << "): " << endl << "> ";
    getline(cin, phone);
    contacts[position].phone = stoi(phone);

    cout << "Enter Email (" << contacts[position].email << "): " << endl << "> ";
    getline(cin, contacts[position].email);
}

/**
 * Sort contact list by Phone in ascending order using Bubble sort algorithm
 * @param contacts
 * @param totalContacts
 */
void bubbleSortAsc(Contact *contacts, int totalContacts) {
    int i, j, flag = 1;
    Contact tempContact;

    // sort using bubble sort
    for(i = 1; (i < totalContacts) && flag; i++) {
        flag = 0;
        for (j=0; j < (totalContacts - 1); j++) {
            if (contacts[j+1].phone < contacts[j].phone) {
                // swap phones
                tempContact = contacts[j];
                contacts[j] = contacts[j+1];
                contacts[j+1] = tempContact;

                flag = 1;               // indicates that a swap occurred
            }
        }
    }
}

/**
 * Sort contact list by Phone in descending order using Bubble sort algorithm
 * @param contacts
 * @param totalContacts
 */
void bubbleSortDesc(Contact *contacts, int totalContacts) {
    int i, j, flag = 1;
    Contact tempContact;

    // sort using bubble sort
    for(i = 1; (i < totalContacts) && flag; i++) {
        flag = 0;
        for (j=0; j < (totalContacts - 1); j++) {
            if (contacts[j+1].phone > contacts[j].phone) {
                // swap phones
                tempContact = contacts[j];
                contacts[j] = contacts[j+1];
                contacts[j+1] = tempContact;

                flag = 1;               // indicates that a swap occurred
            }
        }
    }
}

/**
 * Sorts contact list in the specific order
 * @param sortAsc
 * @param contacts
 * @param totalContacts
 */
void sortContactsList(bool sortAsc, Contact *contacts, int totalContacts) {
    if (sortAsc) {
        // ascending order
        bubbleSortAsc(contacts, totalContacts);
    } else {
        // descending order
        bubbleSortDesc(contacts, totalContacts);
    } // else
}

/**
 * Displays the contact list
 * @param contacts
 * @param totalContacts
 */
void printContactsList(Contact *contacts, int totalContacts) {
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Contact List:" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    if (totalContacts > 0) {
        // print data
        cout << "Phone\t\tFirst Name\tLast Name\t\tEmail" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        for (int i=0; i<totalContacts; i++) {
            cout << contacts[i].phone << "\t\t" << contacts[i].firstName << "\t\t" <<
                    contacts[i].lastName << "\t\t\t" << contacts[i].email << endl;
        }
    } else {
        cout << "No contacts added yet.";
    }

    cout << "---------------------------------------------------------------------------------------" << endl;
}

/**
 * Search for a contact phone number
 * @param searchPhone
 * @param contacts
 * @param totalContacts
 * @return 
 */
int searchContactByPhone(int searchPhone, Contact *contacts, int totalContacts) {
    int found = -1;
    int i = 0;
    
    // search for contact
    while (found < 0 && i < totalContacts) {
        if (searchPhone == contacts[i].phone) {
            found = i;
        } else {
            i++;
        }
    }

    return found;
}

/**
 * Search for a contact first name or last name
 * @param searchName
 * @param contacts
 * @param totalContacts
 * @return 
 */
int searchContactByName(string searchName, Contact *contacts, int totalContacts) {
    int found = -1;
    int i = 0;
    
    // search for contact
    while (found < 0 && i < totalContacts) {
        if ((searchName == contacts[i].firstName) || (searchName == contacts[i].lastName)) {
            found = i;
        } else {
            i++;
        }
    }

    return found;
}

/**
 * Search for a contact email
 * @param searchEmail
 * @param contacts
 * @param totalContacts
 * @return 
 */
int searchContactByEmail(string searchEmail, Contact *contacts, int totalContacts) {
    int found = -1;
    int i = 0;
    
    // search for contact
    while (found < 0 && i < totalContacts) {
        if (searchEmail == contacts[i].email) {
            found = i;
        } else {
            i++;
        }
    }

    return found;
}

/**
 * Display a specific contact information
 * @param contacts
 * @param position
 */
void printContact(Contact *contacts, int position) {
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Contact:" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    // print data
    cout << "Phone\t\tFirst Name\tLast Name\t\tEmail" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << contacts[position].phone << "\t\t" << contacts[position].firstName << "\t\t" <<
            contacts[position].lastName << "\t\t\t" << contacts[position].email << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
}

/**
 * Handles search options
 * @param contacts
 * @param totalContacts
 */
void searchContacts(Contact *contacts, int totalContacts) {
    int option = -1;
    int phone = -1;
    string name = "";
    string email = "";
    int found = -1;
    bool returnToMainScreen = false;

    // main program loop
    while (!returnToMainScreen) {
        printSearchMenu();
        cin >> option;
        
        cin.ignore(); // clean buffer
        
        switch (option) {
            case 1:
                cout << "Enter Phone: ";
                cin >> phone;

                found = searchContactByPhone(phone, contacts, totalContacts);

                if (found >= 0) {
                    printContact(contacts, found);
                    manageContact(contacts, totalContacts, found);
                    returnToMainScreen = true;
                } else {
                    cout << "---------------------------------------------------------------------------------------" << endl;
                    cout << "No contact Found." << endl;
                    cout << "---------------------------------------------------------------------------------------" << endl;
                }
                
                found = -1;
                break;
            case 2:
                cout << "Enter Name: ";
                getline(cin, name);

                found = searchContactByName(name, contacts, totalContacts);

                if (found >= 0) {
                    printContact(contacts, found);
                    manageContact(contacts, totalContacts, found);
                    returnToMainScreen = true;
                } else {
                    cout << "---------------------------------------------------------------------------------------" << endl;
                    cout << "No contact Found." << endl;
                    cout << "---------------------------------------------------------------------------------------" << endl;
                }

                found = -1;
                break;
            case 3:
                cout << "Enter Email: ";
                getline(cin, email);

                found = searchContactByEmail(email, contacts, totalContacts);

                if (found >= 0) {
                    printContact(contacts, found);
                    manageContact(contacts, totalContacts, found);
                    returnToMainScreen = true;
                } else {
                    cout << "---------------------------------------------------------------------------------------" << endl;
                    cout << "No contact Found." << endl;
                    cout << "---------------------------------------------------------------------------------------" << endl;
                }

                found = -1;
                break;
            case 0:
                returnToMainScreen = true;
                break;
            default:
                cout << "Invalid Option. Try again." << endl;
        }
    }
}

/**
 * Handle sorting options
 * @param contacts
 * @param totalContacts
 */
void sortContacts(Contact *contacts, int totalContacts) {
    int option = -1;
    bool returnToMainScreen = false;

    // main program loop
    while (!returnToMainScreen) {
        printSortMenu();
        cin >> option;
        
        cin.ignore(); // clean buffer
        
        switch (option) {
            case 1:
                sortContactsList(true, contacts, totalContacts);
                cout << endl << "Sorted List:" << endl;
                printContactsList(contacts, totalContacts);
                option = 0;
                break;
            case 2:
                sortContactsList(false, contacts, totalContacts);
                cout << endl << "Sorted List:" << endl;
                printContactsList(contacts, totalContacts);
                option = 0;
                break;
            case 0:
                returnToMainScreen = true;
                break;
            default:
                cout << "Invalid Option. Try again." << endl;
        }
    }
}

/**
 * Handle search sub-menu options
 * @param contacts
 * @param totalContacts
 * @param position
 */
void manageContact(Contact *contacts, int totalContacts, int position) {
    int option = -1;
    bool returnToMainScreen = false;

    // main program loop
    while (!returnToMainScreen) {
        printSearchSubMenu();
        cin >> option;
        
        cin.ignore(); // clean buffer
        
        switch (option) {
            case 1:
                editContact(contacts, position);
                cout << "Done!" << endl;
                returnToMainScreen = true;
                break;

            case 0:
                returnToMainScreen = true;
                break;

            default:
                cout << "Invalid Option. Try again." << endl;
        }
    }
}
