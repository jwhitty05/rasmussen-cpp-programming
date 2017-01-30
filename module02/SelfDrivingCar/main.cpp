/*
    Author: Leonardo Vallejos
    Date: January 14, 2017
    FileName: main.cpp
    Purpose: This program simulates the decisions needed when a self-driving automobile makes a left turn at a traffic light.
    Input: The program takes relevant input from the user at each decision point regarding the current condition in question.
    Output: The program outputs whether the self-driving auto has decided to turn or has decided to wait.
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * Main program
 */
int main(int argc, char** argv) {
    int color = 0;
    int signal = 0;
    bool wait = true;
    bool ok = false;
    string traffic = "";

    // 1. check traffic light
    // loop until a valid option is entered
    while (!ok) {
        cout << "> Select traffic light color:" << endl;
        cout << "1. red" << endl;
        cout << "2. yellow" << endl;
        cout << "3. green" << endl;

        cin >> color;

        switch (color) {
            case 1:
            case 2:
                wait = true;
                ok = true;
                break;
            case 3:
                wait = false;
                ok = true;
                break;
            default:
                wait = true; // let's wait when the option is invalid
                cout << "Invalid option. Try again." << endl;
        }
    }
    
    // 2. check oncoming traffic
    if (wait == false) {
        ok = false;
        // loop until a valid option is entered
        while (!ok) {
            cout << "> Is there any oncoming traffic? <y/n>" << endl;
            cin >> traffic;

            if (traffic == "y") {
                wait = true;
                ok = true;
            } else if (traffic == "n") {
                wait = false;
                ok = true;
            } else {
                cout << "Invalid option. Try again." << endl;
            }
        }
    }
    
    // 3. check turn signal
    if (wait == false) {
        ok = false;
        // loop until a valid option is entered
        while (!ok) {
            cout << "> Enter turn signal status:" << endl;
            cout << "1. set to indicate a left turn" << endl;
            cout << "2. set to indicate a right turn" << endl;
            cout << "3. not set" << endl;

            cin >> signal;

            switch (signal) {
                case 1:
                    wait = false;
                    ok = true;
                    break;
                case 2:
                case 3:
                    wait = true;
                    ok = true;
                    break;
                default:
                    wait = true; // let's wait when the option is invalid
                    cout << "Invalid option. Try again." << endl;
            }
        }
    }
    
    // display result
    if (wait) {
        cout << "Self-driving car waits." << endl;
    } else {
        cout << "Self-driving car turns left." << endl;
    }
    
    return 0;
}

