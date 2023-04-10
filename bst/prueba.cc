// System includes

#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <cassert>

/************************************************************/
// Local includes

#include "SearchTree.hpp"

/************************************************************/
// Using declarations

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::ostringstream;
using std::vector;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual);

/************************************************************/

template<typename T>
void
tree_insert (SearchTree<T>& tree, const vector<T>& values)
{
    for (T value : values)
    {
        tree.insert (value);
    }
}

int      
main (int argc, char* argv[]) 
{        
    SearchTree<int> T;
    tree_insert (T, {1});
    cout << T << endl;
    tree_insert (T, {2});
    cout << T;
    tree_insert (T, {1, 2, 3, 4});
    cout << T;
    // For holding the actual result
    ostringstream output;
    // Put the actual result into the output stream
    output << T;
    printTestResult ("no-arg ctor", "[ 1 2 3 4 ]", output);

    // Must clear the output stream each time
    output.str ("");
    



    return EXIT_SUCCESS;
}

/*TEST_CASE ("copy constructor (7)")
{
    SearchTree<int> tree_a;

    tree_insert (tree_a, {1, 2, 3, 4});

    SearchTree<int> tree_b (tree_a);

    std::cout << "d\n";
    SECTION ("copy constructor - state of tree after copy construct [3.00]")
    {
        std::cout << "y\n";
        REQUIRE_TREE (tree_b, "[ 1 2 3 4 ]", 3);
    }

    // Dependencies: size
    SECTION ("copy constructor - size of tree after copy construct [0.20]")
    {
        REQUIRE (tree_b.size () == 4);
    }

    // Dependencies: iterator decrement, end
    SECTION ("copy constructor - head links after copy construct [0.80]")
    {
        REQUIRE_HEAD (tree_b, 1, 4, 1);
    }

    // Dependencies: clear
    SECTION ("copy constructor - separate from original [3.00]")
    {
        tree_b.clear ();
        tree_b.insert (5);

        ostringstream stream_a, stream_b;

        tree_a.printInOrder (stream_a);
        tree_b.printInOrder (stream_b);

        REQUIRE (stream_a.str () != stream_b.str ());
    }
}*/

/************************************************************/

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual)
{
  cout << "Test: " << test << endl;
  cout << "==========================" << endl;
  cout << "Expected: " << expected << endl;
  cout << "Actual  : " << actual.str () << endl;
  cout << "==========================" << endl << endl;

  // Ensure the two results are the same
  assert (expected == actual.str ());
}

/************************************************************/
