/*
  Filename   : Interest.cpp
  Author     : Miguel Armendáriz Llanos
  Course     : CSCI 362-01
  Date       : 01/24/2021
  Assignment : CD Interest
  Description: Calculate the interest earned on a certificate of deposit (CD) over a specified period depending on promt chosen by the user
*/
/************************************************************/
// System includes

#include <cstdio>
#include <iostream>


/************************************************************/
// Local includes




/************************************************************/
// Using declarations

using std::cout;
using std::cin;


/************************************************************/
// Function prototypes/global vars/type definitions

// Inform user what program will do
void   
printIntro ();

// Print the header followed by all the rows.
void   
printTable (int numRows, double balance, double rate);

// Print one row of table. "interest" is a dollar amount,
//   not a rate.
void   
printRow (int rowNum, double balance, double interest);

// Calculate interest given a balance and percentage rate (like 7.2%)
double 
calcInterest (double balance, double rate);

/************************************************************/

int
main (int argc, char* argv[])
{
    double iBalance,iRate;
    int nYears;
    printIntro ();
    cout << "Please enter the initial balance: ";
    cin >> iBalance;
    cout << "\nPlease enter the interest rate: ";
    cin >> iRate;
    cout << "\nPlease enter the number of years: ";
    cin >> nYears;
    cout << "\n";
    printTable (nYears,iBalance,iRate);
    
}

/************************************************************/

void
printIntro ()
{
    
    cout << "This program will calculate the interest earned on a CD over a period of several years.\n";
}

// Print the header followed by all the rows.
void   
printTable (int numRows, double balance, double rate)
{
    double auxBalance = balance;
    printf("Year     Balance     Interest     New Balance\n");
    printf("----     -------     --------     -----------\n");
    for(int i = 1; i <= numRows; ++i){
        printRow(i,auxBalance,calcInterest(auxBalance,rate));
        auxBalance += calcInterest(auxBalance,rate);

    }
}

// Print one row of table. "interest" is a dollar amount,
//   not a rate.
void   
printRow (int rowNum, double balance, double interest)
{
    setlocale(LC_NUMERIC, "");
    printf("%-4d\t",rowNum);
    printf("%'5.2f\t",balance);
    printf("%'6.2f     ",interest);
    printf("%'7.2f\n",balance+interest);
}

// Calculate interest given a balance and percentage rate (like 7.2%)
double 
calcInterest (double balance, double rate){
    return balance*(rate/100);
}
  