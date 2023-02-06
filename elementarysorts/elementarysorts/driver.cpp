/*
 In general, your program should be split up into different sections

 Section 0: Top Comment Block
   Always include the following:
   - First and last name
   - Last date of modification
   - Course + Section
   - Assignment Name
   - File Description

 Section 1: Includes (must be in the following order)
   1. C++ standard library includes (e.g. <algorithm>)
   2. C library includes (e.g. <math.h> or <cmath>)
   3. System library includes (<name.h> but are not part of the C or C++ standard)
   4. User includes (ones contained in quotes -- e.g. "Timer.hpp")

 Section 2: Preprocessor Definitions
   - Anything that starts with #define (or appropriate guards around it

 Section 3: Compile-time constants, type aliases, using directives, type definitions
   - constexpr Type name = value-expr;
   - using Type = type-expr;
   - using std::cout;
   - declarations of file-scoped struct/class/union

 Section 4: Global variables -- NOTE: use sparingly and ONLY if necessary

 Section 5: Forward declarations for non-template functions
   - A forward declaration is a function without a body.
   - Any default parameters MUST be specified in the forward declaration

 Section 6: Template function implementations
   - Any functions beginning with 'template <...>'

 Section 7: main() function implementation [[[entry point of program]]]
   - main must always have the following signature:
     int main (int argc, char* argv[])

 Section 8: Implementations of non-template functions
   - Must be listed in the SAME ORDER as the forward declarations above
   - REMINDER: whenever you update the parameter types/counts, update
     them in BOTH locations. Otherwise you can get a compiler error!
*/

// Author: Professor William Killian
// Date: 2019 May 17
// Class: CSCI 362.93 - Data Structures
// Assignment: 2a - Analyzing Sorting Algorithms
//
// A high-level description of what this file provides/does should go here

// Includes
////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include <vector>

// TODO: add include you may use here

#include "sort.hpp"

// Forward declarations
////////////////////////////////////////////////////////////////////////////////

// -- for any helper functions you write
using std::cin;
using std::cout;
using std::minstd_rand;
using std::sort;
using std::string;
using std::vector;

// Main
////////////////////////////////////////////////////////////////////////////////

int
main (int argc, char* argv[])
{
    int n, seed;
    char type;
    string algorithm, sorted;
    Statistics stats;
    cout << "N         ==> ";
    cin >> n;
    cout << "Algorithm ==> ";
    cin >> algorithm;
    cout << "Type      ==> ";
    cin >> type;
    vector<int> v;

    if (type == 'a')
    {
        for (int i = 0; i < n; ++i)
        {
            v.push_back (i);
        }
    }
    else if (type == 'd')
    {
        for (int i = n; i > 0; --i)
        {
            v.push_back (i);
        }
    }
    else
    {
        cout << "Seed      ==> ";
        cin >> seed;
        std::linear_congruential_engine<std::uint_fast32_t, 567, 0, 9999> gen;
        gen.seed (seed);
        int value;
        for (int i = 0; i < n; ++i)
        {
            value = gen ();
            v.push_back (value);
        }
    }
    vector<int> vector_copy = v;
    sort (vector_copy.begin (), vector_copy.end ());
    if (algorithm == "bubble")
    {
        bubbleSort (v, stats);
    }
    if (algorithm == "insertion")
    {
        insertionSort (v, stats);
    }
    if (algorithm == "selection")
    {
        selectionSort (v, stats);
    }
    if (v == vector_copy)
    {
        sorted = "yes";
    }
    else
    {
        sorted = "no";
    }

    cout << "N         ==> ";
    printf ("%d\n", n);
    cout << "Algorithm ==> ";
    cout << algorithm;
    cout << "\n";
    cout << "Type      ==> ";
    printf ("%c \n", type);

    cout << "# Compares: ";
    printf ("%d\n", stats.numCompares);
    cout << "# Swaps   : ";
    printf ("%d\n", stats.numSwaps);
    cout << "Sort ok?    ";
    cout << sorted;
    cout << "\n";

    return 0;
}


