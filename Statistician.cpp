/***************************************************
 Name: Your Name
 Course: 
 Date: 
 Assignment: 
 Description: 
 
 ***************************************************/

#include <iostream>

#include "Statistician.h"

using std::cin;
using std::cout;

// Function Implementations
// **************************************************

// Finds the largest value in the passed vector
// Assumes nums is not empty
float
maximum (const std::vector<float>& nums)
{
    float max = *nums.begin ();
    for (auto i = nums.begin (); i != nums.end (); ++i)
    {
        if (max < *i)
        {
            max = *i;
        }
    }

    return max;
}

// Finds the smallest value in the passed vector
// Assumes nums is not empty
float
minimum (const std::vector<float>& nums)
{
    float min = *nums.begin ();
    for (auto i = nums.begin (); i != nums.end (); ++i)
    {
        if (min > *i)
        {
            min = *i;
        }
    }

    return min;
}

// Finds the sum of values from the passed vector
// Should return zero if the vector is empty
float
sumOfValues (const std::vector<float>& nums)
{
    float sum = 0;
    for (auto i = nums.begin (); i != nums.end (); ++i)
    {
        sum += *i;
    }
    return sum;
}

// Finds the average of all values from the passed vector
// assumes nums is not empty
float
average (const std::vector<float>& nums)
{
    float sum = sumOfValues (nums);
    size_t size = nums.size ();

    return sum / size;
}

// Creates and returns a new vector. Reads in count number
// of values from the user by prompting for each one
// should return an empty vector if count <= 0
std::vector<float>
populate (int count)
{
    std::vector<float> result;
    float element;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter value ==> ";
        cin >> element;
        result.push_back (element);
    }

    return result;
}
