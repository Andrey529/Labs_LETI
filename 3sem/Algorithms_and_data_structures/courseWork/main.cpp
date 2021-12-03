#include <iostream>
#include <string>
#include "headers/functions/functions.h"

int main() {


    auto *expression = new std::string();
//    inputExpression(expression);
    *expression = "30 15 tg ";
    calculationPostfix(expression);

//    std::string str = "2.2";
//    double d = std::stod(str);
//    std::cout << d << std::endl;

    return 0;
}