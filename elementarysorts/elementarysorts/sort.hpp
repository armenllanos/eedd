// Author: Professor William Killian
// Date: 2019 May 17
// Class: CSCI 362.93 - Data Structures
// Assignment: 2a - Analyzing Sorting Algorithms
//
// Description:
//
// Header file for templated sorting algorithms, specifically
// bubble sort (optimized), insertion sort, and selection sort.
// Includes a 'Statistics' datatype for aggregating counts for
// swaps and comparisons.

#ifndef SORTING_ALGORITHMS_HPP_
#define SORTING_ALGORITHMS_HPP_

#include <vector>

struct Statistics
{
    // default constructs swaps and compares to zero
    std::size_t numSwaps{0};
    std::size_t numCompares{0};
};

template<typename T>
void
bubbleSort (std::vector<T>& v, Statistics& s)
{
    bool swap = true;
    for (int i = v.size () - 1; i >= 1; --i)
    {
        swap = false;
        for (int j = 0; j < i; ++j)
        {
            s.numCompares++;
            if (v[j] > v[j + 1])
            {
                std::swap (v[j], v[j + 1]);
                s.numSwaps++;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}

template<typename T>
void
insertionSort (std::vector<T>& v, Statistics& s)
{
    int x, j;
    for (int i = 1; i < v.size (); ++i)
    {
        x = v[i];
        j = i;
        while (j >= 1 && x < v[j - 1])
        {
            s.numCompares++;
            v[j] = v[j - 1];
            s.numSwaps++;
            --j;
        }
        v[j] = x;
    }
}

template<typename T>
void
selectionSort (std::vector<T>& v, Statistics& s)
{
    int i = 0;
    int min;
    for (i = 0; i < v.size () - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < v.size (); ++j)
        {
            s.numCompares++;
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            std::swap (v[i], v[min]);
            s.numSwaps++;
        }
    }
}

#endif
