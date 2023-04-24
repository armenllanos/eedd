/* File: DivideAndConquer.hpp
 Author: Miguel Armendáriz Llanos
Course     : CSCI 362
Description: Implementation of divide and conquer and necessary functions for making these sorts 
             */

#ifndef DIVIDE_AND_CONQUER_HPP_
#define DIVIDE_AND_CONQUER_HPP_

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

// NOTE: you are forbidden from using anything from <algorithm> for this assignment
//       EXCEPT for std::copy

namespace SortUtils
{

// [9]
// Given a RandomAccessRange [first, last), determine where the "midpoint"
// would be and perform the following steps:
// order *first, *mid, *std::prev(last) in such a way such that
//   *first <= *mid <= *std::prev(last)
//
// returns an iterator to mid -- a.k.a. the median
//
template<typename Iter>
Iter
median3 (Iter first, Iter last)
{
    auto size = (std::distance (first, last)) / 2;
    Iter mid = std::next (first, size);

    if (*mid < *first)
    {
        std::swap (*mid, *first);
    }
    if (*mid > *std::prev (last))
    {
        std::swap (*mid, *std::prev (last));
    }
    if (*mid < *first)
    {
        std::swap (*mid, *first);
    }
    return mid;
}

// [10]
// Takes two sorted ranges [first1, last1) and [first2, last2)
// and "merges" them by copying values into the iterator starting
// at "out". Uses operator< for comparing values
//
// Returns the iterator of one-past-the-last where we wrote to out
//
template<typename Iter1, typename Iter2, typename OIter>
OIter
merge (Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, OIter out)
{
    if ((first1 == last1) && (first2 == last2))
    {
        return out;
    }
    else if (first1 == last1)
    {
        *out = *first2;
        return SortUtils::merge (first1, last1, ++first2, last2, ++out);
    }
    else if (first2 == last2)
    {
        *out = *first1;
        return SortUtils::merge (++first1, last1, first2, last2, ++out);
    }
    else
    {
        if (*first2 > *first1)
        {
            *out = *first1;
            return SortUtils::merge (++first1, last1, first2, last2, ++out);
        }
        else
        {
            *out = *first2;
            return SortUtils::merge (first1, last1, ++first2, last2, ++out);
        }
    }

    // TODO
}

// [15]
// Takes a RandomAccessRange [first, last) and partitions the data into
// three groups -- this should be accomplished in a SINGLE PASS Big-O: O(N)
//
// Group 1: all values in [first, last) < pivot
// Group 2: all values in [first, last) == pivot
// Group 3: all values in [first, last) > pivot
//
// [ ... Group 1 ... | ... Group 2 ... | ... Group 3 ... ]
//                   ^                 ^
//                   p1                p2
//
// Returns a pair of iterators pointing to "p1" and "p2" above
//
// Hint: See separate Three Way Partition explanation in handout.
//
template<typename Iter, typename Value>
std::pair<Iter, Iter>
partition (Iter first, Iter last, Value const& pivot)
{
    Iter lo = first;
    Iter eq = first;
    Iter hi = last;
    while (eq != hi)
    {
        if (*eq < pivot)
        {
            std::swap (*lo, *eq);
            lo = std::next (lo);
            eq = std::next (eq);
        }
        else if (*eq > pivot)
        {
            hi = std::prev (hi);
            std::swap (*eq, *hi);
        }
        else
        {
            eq = std::next (eq);
        }
    }

    return {lo, hi};

    // TODO
}

// [10]
// Given a RandomAccessRange, recursively call partition on either the
// left half or right half until you have found the nth largest element
//
// A call to nth_element (v.begin(), v.end(), 0) will return the min
// A call to nth_element (v.begin(), v.end(), v.size() - 1) will return the max
// A call to nth_element (v.begin(), v.end(), v.size() / 2) will return the median
//
// Precondition:
//   std::distance (begin, end) > n
//
// Hints:
//  - n will change if you need to recurse on the right half
//  - No recursion happens if "index of" n is between "index of" p1 and p2
//    remember: p1 and p2 are the return values to partition.
//  - call median3 to get a pivot value
//  - when calling partition, remember to dereference the iterator returns by median3
//
template<typename Iter>
Iter
nth_element (Iter first, Iter last, size_t n)
{
    auto size = std::distance (first, last);

    auto pivot = *median3 (first, last);
    auto p = SortUtils::partition (first, last, pivot);
    auto index = std::distance (first, p.first);

    if (index <= n && n < std::distance (first, p.second))
    {
        return p.first;
    }
    else if (index > n)
    {
        return nth_element (first, p.first, n);
    }
    else
    {
        return nth_element (p.second, last,
                            n - std::distance (first, p.second));
    }
    // TODO
    // auto [p1, p2] = SortUtils::partition (...);
}

// [10]
// Given a RandomAccessRange, sort using merge sort
//
// Precondition:
//   std::distance (begin, end) > 0
//
// Hints:
//   - You will need a vector to act as a temporary buffer.
//   - The merge function will expect that vector to already be big enough
//     to hold all of the elements.
//

template<typename Iter>
void
merge_sort (Iter first, Iter last)
{
    using T = std::remove_reference_t<decltype (*std::declval<Iter> ())>;
    auto size = std::distance (first, last);

    if (size == 1)
    {
        return;
    }
    auto mid = std::next (first, size / 2);
    std::vector<T> buffer (size);
    SortUtils::merge_sort (first, mid);
    SortUtils::merge_sort (mid, last);
    SortUtils::merge (first, mid, mid, last, buffer.begin ());
    std::copy (buffer.begin (), buffer.begin () + size, first);
    // TODO
    // T is the type of data we are sorting
}

// Provided for you -- no need to change.
template<typename Iter>
void
insertion_sort (Iter first, Iter last)
{
    for (Iter i = first; i != last; ++i)
    {
        for (Iter j = i; j != first; --j)
        {
            if (*(j - 1) > *j)
            {
                std::iter_swap (j - 1, j);
            }
            else
            {
                break;
            }
        }
    }
}

// [10]
// Given a RandomAccessRange, sort using quick sort
//
// Precondition:
//   std::distance (begin, end) > 0
//
// Hints:
//   - median3 will be called to find the pivot
//   - remember to dereference the iterator returned by median3 to get the pivot value
//   - partition should be called
//   - if there are fewer than 16 elements, use the provided insertion sort instead
//
template<typename Iter>
void
quick_sort (Iter first, Iter last)
{
    // TODO
    auto size = std::distance (first, last);
    if (size < 16)
    {
        insertion_sort (first, last);
        return;
    }
    // T is the type of data we are sorting
    using T = std::remove_reference_t<decltype (*std::declval<Iter> ())>;
    auto pivot = *median3 (first, last);
    auto parts = SortUtils::partition (first, last, pivot);
    SortUtils::quick_sort (first, parts.first);
    SortUtils::quick_sort (parts.second, last);
}

} // end namespace util

#endif
