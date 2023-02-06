/***************************************************
 Name: Miguel Armendáriz Llanos
 Course: 362
 Date: 28/1/2023
 Assignment: statredux
 Description: Usage of a vector, filling it, and deciding its size
 
 ***************************************************/

// Include Directives
// **************************************************
#include <iostream>
// TODO: other includes go here

#include "Statistician.h"

// Using Statements
// **************************************************
using std::cin;
using std::cout;
// TODO: any extra using statements would go here

// Forward Declarations
// **************************************************

// TODO: any functions you implement AFTER main must be defined here

// Main
// **************************************************

int
main (int argc, char* argv[])
{
    int numVal;
    float valor;
    std::vector<float> myVector;
    cout << "Enter number of values ==> ";
    cin >> numVal;
    myVector = populate (numVal);

    cout << "\nThe statistics of all 5 values are:\n";
    printf ("  Sum: %.2f\n", sumOfValues (myVector));
    printf ("  Avg: %.2f\n", average (myVector));
    printf ("  Min: %.2f\n", minimum (myVector));
    printf ("  Max: %.2f\n", maximum (myVector));
}

// Function Implementations
// **************************************************

// TODO: any functions you call within main that are a part of this
// file must be implemented AFTER main
