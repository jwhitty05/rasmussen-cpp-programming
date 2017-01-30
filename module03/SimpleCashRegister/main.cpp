/*
    Author: Leonardo Vallejos
    Date: January 21, 2017
    FileName: main.cpp
    Purpose: This program simulates a simple cash register application.
    Input: The program inputs five floating point numbers that represent purchased items.
           The program will input the numbers one at a time
    Output: The program will output the items, item taxes, item subtotals, items total, tax total, and total due.
            The output will be formatted in columns with a header above the fields.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const float taxRate = 7; // 7% taxable rate
    float itemCost[5];
    float itemTax[5];
    float itemSubtotal[5];
    float itemTotal = 0;
    float taxTotal = 0;
    float totalDue = 0;
    
    // set decimals to display
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);

    for (int i=0; i<5; i++) {
        cout << "* Please enter a purchased item's Cost: ";
        cin >> itemCost[i];
        
        // calculate tax and subtotal
        itemTax[i] = (itemCost[i] * taxRate) / 100;
        itemSubtotal[i] = itemCost[i] + itemTax[i];
        
        // calculate total
        itemTotal += itemCost[i];
        taxTotal += itemTax[i];
        totalDue += itemSubtotal[i];
    }

    cout << "Item Cost \t\t Item Tax \t\t Item Subtotal" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i=0; i<5; i++) {
        cout << "\t" << itemCost[i] << "\t\t\t" << itemTax[i] << "\t\t\t" << itemSubtotal[i] << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "Items Total \t\t Tax Total \t\t Total Due" << endl;
    cout << "\t" << itemTotal << "\t\t\t" << taxTotal << "\t\t\t" << totalDue << endl;
    
    return 0;
}

