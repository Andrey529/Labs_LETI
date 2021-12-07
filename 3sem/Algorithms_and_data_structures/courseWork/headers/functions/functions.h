#ifndef COURSEWORK_FUNCTIONS_H
#define COURSEWORK_FUNCTIONS_H

#include "../stack/stack.h"
#include <string>
#include <iostream>
#include <math.h>

void inputExpression(std::string *expression); // inputs an expression and checks it correctness
std::string convertInfixToPostfix(std::string expression); // converts expression in infix to postfix form
double calculationPostfix(std::string *expression); // calculates the result of an expression in postfix form
bool approximatelyEqual(double a, double b, double epsilon);

template<typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

enum containerType{
    LEFTPARENTHESIS,
    RIGHTPARENTHESIS,
    OPERATOR,
    OPERAND,
    FUNCTION,
};

//#include "../../src/functions/functions.cpp"


#endif //COURSEWORK_FUNCTIONS_H