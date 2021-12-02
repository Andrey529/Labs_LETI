#ifndef COURSEWORK_FUNCTIONS_H
#define COURSEWORK_FUNCTIONS_H

#include "../stack/stack.h"
#include <string>
#include <iostream>

void inputExpression(std::string *expression); // inputs an expression and checks it correctness
void convertToPostfix(std::string *expression); // converts expression in infix to postfix form
void calculationPostfix(std::string *expression); // calculates the result of an expression in postfix form

#endif //COURSEWORK_FUNCTIONS_H