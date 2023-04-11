// System includes

#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <cassert>
#include <cmath>

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
template<typename T>
void
tree_erase (SearchTree<T>& tree, const vector<T>& values)
{
    for (T value : values)
    {
        tree.erase (value);
        cout << "smallest = " << tree.end().m_nodePtr->right->data << endl;
    }
}

int      
main (int argc, char* argv[]) 
{        
    SearchTree<int> T;
    tree_insert (T, {4, 2, 1, 3, 6, 5, 7});
    tree_erase(T, {4, 3, 1, 2});
    int s = T.size();
    int i = 0;
    int k;
    cout << T << endl;
    while (T.size () > 0)
    {
        k = *(--T.end ());
        cout << "\r(i = " << i << ")";
        cout << "\tErasing: " << k;
        cout << "\tPercentage: (" << T.size () << " / " << s << ") " << (std::ceil((T.size ()/(double)s) * 100.0 * 100.0) / 100.0) << "%" << endl;
        T.erase (k);
        cout << T << endl;
        ++i;
    }
    


    
    return EXIT_SUCCESS;
}


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
