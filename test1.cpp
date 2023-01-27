/************************************************************/
// System includes

#include <iostream>

/************************************************************/
// Local includes


/************************************************************/
// Using declarations

using std::cout;
using std::endl;

/************************************************************/
// Function prototypes/global vars/type definitions

/************************************************************/


int main() {
int sum = 0;
  for (int k=1; k<11; k++)   {
    sum += k;
  }
  cout << "The sum is: " << sum << endl;
  return 0;
}