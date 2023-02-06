/***************************************************
 Name: Miguel Armendariz Llanos
 Course: 362
 Date: 
 Assignment: 
 Description: 
 
 ***************************************************/

// TODO: other includes go here

#include "Statistician.h"
#include <cstddef>
#include <iostream>

// Function Implementations
// **************************************************
using std::cin;
using std::cout;
// Finds the largest value in the passed vector
// Assumes nums is not empty
float
maximum (const std::vector<float>& nums)
{
    float max = nums[0];
    int sizeV = std::size (nums);
    for (int i = 0; i < sizeV; ++i)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

// Finds the smallest value in the passed vector
// Assumes nums is not empty
float
minimum (const std::vector<float>& nums)
{
    float min = nums[0];
    int sizeV = std::size (nums);
    for (int i = 0; i < sizeV; ++i)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    return min;
}

// Finds the sum of values from the passed vector
// Should return zero if the vector is empty
float
sumOfValues (const std::vector<float>& nums)
{
    float sum;
    int sizeV = std::size (nums);
    for (int i = 0; i < sizeV; ++i)
    {
        sum += nums[i];
    }
    return sum;
}

// Finds the average of all values from the passed vector
// assumes nums is not empty
float
average (const std::vector<float>& nums)
{
    float sum = sumOfValues (nums);
    sum /= std::size (nums);
    return sum;
}

// Creates and returns a new vector. Reads in count number
// of values from the user by prompting for each one
// should return an empty vector if count <= 0
std::vector<float>
populate (int count)
{
    int value;
    std::vector<float> result;
    for (int i = 0; i < count; ++i)
    {
        cout << "Enter value ==> ";
        cin >> value;
        result.push_back (value);
    }

    // TODO
    return result;
}
