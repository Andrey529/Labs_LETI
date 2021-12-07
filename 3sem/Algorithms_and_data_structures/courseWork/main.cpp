#include <iostream>
#include <string>
#include "headers/functions/functions.h"

int main() {


    auto *expression = new std::string();
//    inputExpression(expression);
    *expression = "((sin(123 + 56) + cos(15 - -6)) / 2)";

    // ((sin(123 + 56) - cos(15 * 6)) / 2)

    std::cout << *expression << std::endl;

    *expression = convertInfixToPostfix(*expression);

    std::cout << *expression << std::endl;


//    std::cout << calculationPostfix(expression);

//    std::string str = "2.2";
//    double d = std::stod(str);
//    std::cout << d << std::endl;

    return 0;
}