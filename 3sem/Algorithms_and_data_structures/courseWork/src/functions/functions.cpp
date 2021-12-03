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
                if ( (tempStr[0] >= 48 ) && (tempStr[0] <= 57) ) { // operands: (0,1,2,...9)
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else {  // operators: +, -, *, /, ^
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
            else { // tempStr.size() != 1

                if ( (tempStr[1] >= 48) && (tempStr[1] <= 57) || (tempStr[1] == '.')) {  // operands with 2+ symbols (123, 329, 9923785, ...)
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else { // functions: cos, sin, tg, ctg, ln, log, sqrt, abs

                    operand1 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();

                    if (tempStr.size() == 2) { // tg, ln
                        switch (tempStr[0]) {
                            case 't': // tg
                                operand1 = tan(operand1 * M_PI/180);
                                break;
                            case 'l': // ln
                                operand1 = log(operand1);
                                break;
                        }
                    }
                    else if(tempStr.size() == 3) { // cos, sin, ctg, log, abs
                        switch (tempStr[0]) {
                            case 's':  // sin
                                operand1 = sin(operand1);
                                break;
                            case 'l':  // log
                                operand1 = log10(operand1);
                                break;
                            case 'a': // abs
                                operand1 = fabs(operand1);
                                break;
                            case 'c':
                                switch (tempStr[1]) {
                                    case 'o':  // cos
                                        operand1 = cos(operand1);
                                        break;
                                    case 't':  // ctg
                                        operand1 = 1 / tan(operand1);
                                        break;
                                }
                        }
                    }
                    else { // sqrt
                        operand1 = sqrt(operand1);
                    }
                    stackForCalculation.push(operand1);
                }
            }
        }
    }
    std::cout << stackForCalculation.getFront()->getData() << std::endl;
    stackForCalculation.pop();
}
