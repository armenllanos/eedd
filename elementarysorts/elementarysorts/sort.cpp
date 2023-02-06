// Author: Miguel Armendáriz Llanos
// Date: 31/01/2023
// Class: CSCI 362.93 - Data Structures
// Assignment: 2a - Analyzing Sorting Algorithms
//
// Description:

/************************************************************/
// System includes

#include <iostream>


/************************************************************/
// Local includes

#include "sort.hpp"

/************************************************************/
// Using declarations

using std::cout;

/************************************************************/
// Function prototypes/global vars/type definitions


/************************************************************/


template <typename T>
void
bubbleSort (std::vector<T>& v, Statistics& s)
{
    for(int i = v.size()-1; i >= 1; --i)
    {
        bool swap;
        for(int j = 0; j < i; ++j){
            s.numCompares++;
            if(v[j] > v[j+1]){
                std::swap(v[j],v[j+1]);
                s.numSwaps++;
                swap = true;
            }
            if(!swap){
                break;
            }
        }
    }
}

template <typename T>
void
insertionSort (std::vector<T>& v, Statistics& s)
{
    int x,j;
    for(int i = 1; i < v.size(); ++i){
        x =  v[i];
        j = i;
        while(j >= 1 && x < v[j-1]){
             s.numCompares++;
            v[j] = v[j-1];
            s.numSwaps++;
            --j;
        }
        v[j] = x;
    }
}

template <typename T>
void
selectionSort (std::vector<T>& v, Statistics& s)
{
    int min;
    for(i = 0; i < v.size()-1; ++i){
        min = i;
        for(int j = i+1; j <v.size(); ++j){
            s.numCompares++;
            min = j;
        }
        if(i != min){
            std::swap(v[i],v[min]);
            s.numSwaps++;
        }
    }
}