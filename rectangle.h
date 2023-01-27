

/************************************************************/
// Macro

#ifndef RECTANGLE_H
#define RECTANGLE_H


/************************************************************/
// System includes

#include <iostream>

/************************************************************/
// Local includes


/************************************************************/
// Using declarations

using std::cout;
using std::ostream;

/************************************************************/
// Function prototypes/global vars/type definitions


class Rectangle
{
    public:
        Rectangle (double width = 0.0, double length = 0.0);

    double
    calculateArea () const;//Si pones const es que no modificas nada de los atributos de la clase


    double 
    calculatePerimeter () const;
    /*
    SETTERS
    GETTERS
    */
   void 
   display (ostream& outputStream);
};
ostream&
operator<<(ostream& outputStream, const Rectangle& r)

/************************************************************/
#endif
