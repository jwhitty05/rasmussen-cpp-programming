/*
    Author: Leonardo Vallejos
    Date: January 20, 2017
    FileName: main.cpp
    Purpose: This program simulates a simple cash register application.
    Input:

    Output:
 
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

void printMenu();
void addContact(Contact *contacts, int &totalContacts);
void bubbleSortAsc(Contact *contacts, int totalContacts);
void bubbleSortDesc(Contact *contacts, int totalContacts);
void sortContactsList(bool sortAsc, Contact *contacts, int totalContacts);
void printContactsList(Contact *contacts, int totalContacts);
int searchContactByPhone(int searchPhone, Contact *contacts, int totalContacts);
int searchContactByName(int searchName, Contact *contacts, int totalContacts);
int searchContactByEmail(string searchEmail, Contact *contacts, int totalContacts);
void searchContact(Contact *contacts, int totalContacts);

/*
 * Main function 
 */
int main(int argc, char** argv) {
    const int maxContacts = 5000; // max amount of contacts
    Contact contacts[maxContacts]; // array to store the contacts    
    int totalContacts = 0; // current amount of contacts in the list

    addContact(contacts, totalContacts);
    
    
    return 0;
}

void printMenu() {
    cout << "Menu:" << endl;
    cout << "1) Add contact" << endl;
    cout << "2) List contacts" << endl;
    cout << "3) Search contacts" << endl;
    cout << "4) Exit program" << endl;
}

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

void bubbleSortDesc(Contact *contacts, int totalContacts) {
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


void sortContactsList(bool sortAsc, Contact *contacts, int totalContacts) {
    if (sortAsc) {
        // ascending order
        bubbleSortAsc();
    } else {
        // descending order
        bubbleSortDesc();
    } // else
}



void printContactsList(Contact *contacts, int totalContacts) {
    // print data
    cout << endl << "Contact List:" << endl << "-----------------------------" << endl;
    cout << "Phone\t\tFirst Name\tLast Name\t\tEmail" << endl << "-----------------------------" << endl;
    for (int i=0; i<totalContacts; i++) {
        cout << contacts[i].phone << "\t\t" << contacts[i].firstName << "\t" <<
                contacts[i].lastName << "\t\t" << contacts[i].email << endl;
    }
    cout << "-----------------------------" << endl;
}

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

int searchContactByName(int searchName, Contact *contacts, int totalContacts) {
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

void searchContact(Contact *contacts, int totalContacts) {
    int option = 0;

    switch (option) {
        case 1:
            searchContactByPhone();
            break;
        case 2:
            searchContactByName();
            break;
        case 3:
            searchContactByEmail();
            break;
        default:
            cout << "Invalid Option. Try again." << endl;
    }
    
}