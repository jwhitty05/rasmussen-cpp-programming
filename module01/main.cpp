/*
    Author: Leonardo Vallejos
    Date: January 6, 2017
    FileName: main.cpp
    Purpose: The program calculates and outputs the area of a triangle under two circumstances.
    Input: None.
    Output: 
    For the first output:
        The triangle sides measure 3 and 4 at the beginning of the program.
        Integers variables will be used to hold the values of the length of the sides and the area of the triangle.
        Initially the area variable will hold a value of (be initialized to) zero.
        The program then calculates the area of the triangle and places the result of the calculation in the area variable.
        The value of the three variables holding the side lengths and area are to then be output as shown below.
    For the second output:
        Double variables are to be used to hold the values of the length of the sides and the area of the triangle.
        The side variables will be initialized to zero.
        The program then multiplies the integer length values by five and places them in the double type side variables.
        The program then calculates the area of the triangle using the new double type side values and places the result in the new double type area variable.
        The value of the double type variables holding the side lengths and area are to be output as shown below.
        The output should be with a single decimal place after the decimal point.
    Exceptions: None.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // part 1
    int height = 3;
    int base = 4;
    int area;
    
    // calculate area
    area = (height * base) / 2;

    // display output
    cout << "The sides of the triangle measure " << height << " and " << base 
            << ". The area is " << area << "." << endl;

    // -------- 
    // part 2
    double height2 = 0;
    double base2 = 0;
    double area2;

    // calculate
    height2 = height * 5;
    base2 = base * 5;    
    area2 = (height2 * base2) / 2;

    // set decimals to display
    std::cout.precision(1);
    std::cout.setf(std::ios::fixed);

    // display the output
    cout << "The sides of the triangle measure " 
        << height2 << " and " << base2 
        << ". The area is " << area2 << "." << endl;

    return 0;
}

