#include "../../headers/functions/functions.h"

void inputExpression(std::string *expression){
    getline(std::cin, *expression);
//    std::cout << *expression << std::endl;
}

void calculationPostfix(std::string *expression) {

    stack<double> stackForCalculation;
    std::string tempStr;
    double currentOperand;
    double operand1, operand2;
    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) != ' ') {
            tempStr.push_back(*it);
        }
        else {
            if (tempStr.size() == 1) {
                if ( (tempStr[0] >= 48 ) && (tempStr[0] <= 57) ) { // operands
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                }
                else {
                    operand2 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();
                    operand1 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();
                    switch (tempStr[0]) {
                        case '+':
                            operand1 = operand1 + operand2;
                            break;
                        case '-':
                            operand1 = operand1 - operand2;
                            break;
                        case '*':
                            operand1 = operand1 * operand2;
                            break;
                        case '/':
                            operand1 = operand1 / operand2;
                            break;
                        case '^':
                            operand1 = pow(operand1, operand2);
                            break;
                    }
                    stackForCalculation.push(operand1);
                }

            }


            try {
                currentOperand = std::stod(tempStr);
            }
            catch (const std::invalid_argument &e) {
                if (tempStr.size() == 1) { // operators: +, -, *, /, ^



                    switch (tempStr[0]) {

                    }

                }
                else{ // special functons: cos(), sin(), tg(), ctg(), ln(), log(), sqrt(), etc
                    std::cout << "sssss";
                }

            }
            catch (const std::out_of_range &e) {
                std::cerr << e.what();
                std::cerr << "the converted value would fall out of the range of the result type or"
                             "the underlying function (strtof, strtod or strtold) sets errno to ERANGE" << std::endl;
                return;
            }
            stackForCalculation.push(currentOperand);
            tempStr.clear();
        }
    }


    std::cout << stackForCalculation.getFront()->getData() << std::endl;
    stackForCalculation.pop();
}
