/***************************************************
 Name: Your Name
 Course: 
 Date: 
 Assignment: 
 Description: 
 
 ***************************************************/

// Include Directives
// **************************************************
#include <iostream>

#include "Statistician.h"

// Using Statements
// **************************************************
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Forward Declarations
// **************************************************

// Main
// **************************************************

int
main (int argc, char* argv[])
{
    vector<float> nums;
    float min, max, avg, sum;
    size_t count;

    cout << "Enter number of values ==> ";
    cin >> count;

    nums = populate (count);
    sum = sumOfValues (nums);
    min = minimum (nums);
    max = maximum (nums);
    avg = average (nums);

    cout << "\nThe statistics of all " << count << " values are:" << endl;
    cout << "  Sum: " << sum << endl;
    cout << "  Avg: " << avg << endl;
    cout << "  Min: " << min << endl;
    cout << "  Max: " << max << endl;
}

// Function Implementations
// **************************************************
