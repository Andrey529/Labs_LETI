#ifndef COURSEWORK_FUNCTIONS_H
#define COURSEWORK_FUNCTIONS_H

#include "../stack/stack.h"
#include <string>
#include <iostream>
#include <math.h>

void inputExpression(std::string *expression); // inputs an expression and checks it correctness
void convertToPostfix(std::string *expression); // converts expression in infix to postfix form
double calculationPostfix(std::string *expression); // calculates the result of an expression in postfix form
bool approximatelyEqual(double a, double b, double epsilon);
#include "../../src/functions/functions.cpp"

#endif //COURSEWORK_FUNCTIONS_H