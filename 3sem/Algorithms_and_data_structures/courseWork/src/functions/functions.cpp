#ifndef COURSEWORK_FUNCTIONS_CPP
#define COURSEWORK_FUNCTIONS_CPP

#include "../../headers/functions/functions.h"

void inputExpression(std::string *expression){
    getline(std::cin, *expression);
}

void convertInfixToPostfix(std::string *expression) {
    stack<std::string> stackForOperators;
    stack<bool> stackForRightParenthesis;
    std::string functions, result;
    containerType nowTypeOfContainer;

    for (std::string::iterator it = expression->begin(); it != expression->end(); it++) {
        if ((*it) == '(') {
            if (nowTypeOfContainer == containerType::FUNCTION)    stackForRightParenthesis.push(true);
            else    stackForRightParenthesis.push(false);

            nowTypeOfContainer = containerType::LEFTPARENTHESIS;
            stackForOperators.push("("); // положить в стэк
        }
        else if ((*it) == ')') {
            if (nowTypeOfContainer != containerType::RIGHTPARENTHESIS) {
                result.push_back(' ');
            }

            while (stackForOperators.getFront()->getData() != "(") {
                result += stackForOperators.getFront()->getData();
                result.push_back(' ');
                stackForOperators.pop();
            }

            if (stackForRightParenthesis.getFront()->getData()) { // stackForRightParenthesis.getFront()->getData() == true
                result += functions;
                result.push_back(' ');
                functions.clear();
            }
            stackForRightParenthesis.pop();

            nowTypeOfContainer = containerType::RIGHTPARENTHESIS;
        }
        else if( (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.') ) {
            // добавить в конец выходного списка
            nowTypeOfContainer = containerType::OPERAND;
            result.push_back(*it);
        }
        else if ( ((*it) >= 'a') && ((*it) <= 'z') ) {
            if ( (*it) == 'e' ) {
                result += "e";
                continue;
            }
            functions += *it;
            if (functions == "pi") {
                result += "pi";
                functions.clear();
            }
            nowTypeOfContainer = containerType::FUNCTION;
        }
        else if ( ((*it) == '^') || ((*it) == '*') || ((*it) == '/') || ((*it) == '+') || ((*it) == '-') ) {

            if ( (nowTypeOfContainer == containerType::OPERAND) || (nowTypeOfContainer == containerType::FUNCTION) ) {
                result.push_back(' ');
            }
            if (nowTypeOfContainer == containerType::OPERATOR) { // unary minus
                result.push_back('-');
                nowTypeOfContainer = containerType::OPERAND;
                continue;
            }

            nowTypeOfContainer = containerType::OPERATOR;

            if (!stackForOperators.isEmpty()) {
                if ( ((*it) == '^') && (stackForOperators.getFront()->getData() == "^") ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
                else if( (((*it) == '*') || ((*it) == '/')) && ( (stackForOperators.getFront()->getData() == "*")
                    || (stackForOperators.getFront()->getData() == "/") || (stackForOperators.getFront()->getData() == "^")) ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
                else if ( (((*it) == '+') || ((*it) == '-')) && (stackForOperators.getFront()->getData() != "(") ) {
                    result += stackForOperators.getFront()->getData();
                    result.push_back(' ');
                    stackForOperators.pop();
                }
            }
            std::string currentSymbol( 1, *it );
            stackForOperators.push(currentSymbol);
        }
    }

    while ( !stackForOperators.isEmpty() ) {
        if (stackForOperators.getFront()->getData() != "(") {
            result += stackForOperators.getFront()->getData();
            result.push_back(' ');
        }
        stackForOperators.pop();
    }

    *expression = result;
}

double calculationPostfix(std::string *expression) {

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
                if (tempStr[0] == 'e'){
                    currentOperand = M_E;
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else if ( (tempStr[0] >= 48 ) && (tempStr[0] <= 57) ) { // operands: (0,1,2,...9)
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
                            if (operand2 == 0) {
                                throw std::invalid_argument("impossible to do division");
                            }
                            operand1 = operand1 / operand2;
                            break;
                        case '^':
                            operand1 = pow(operand1, operand2);
                            break;
                    }
                    stackForCalculation.push(operand1);
                    tempStr.clear();
                }
            }
            else { // tempStr.size() != 1

                if ( (tempStr[1] >= 48) && (tempStr[1] <= 57) || (tempStr[1] == '.')) {  // operands with 2+ symbols (123, 329, 9923785, ...)
                    currentOperand = std::stod(tempStr);
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else if ( (tempStr.size() == 2) && (tempStr[0] == 'p') && (tempStr[1] == 'i')) {
                    currentOperand = 180;
                    stackForCalculation.push(currentOperand);
                    tempStr.clear();
                }
                else { // functions: cos, sin, tg, ctg, ln, log, sqrt, abs

                    operand1 = stackForCalculation.getFront()->getData();
                    stackForCalculation.pop();

                    if (tempStr.size() == 2) { // tg, ln, pi
                        switch (tempStr[0]) {
                            case 't': // tg
                                if ((int)round(operand1) % 180 == 0){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        operand1 = 0;
                                        break;
                                    }
                                }
                                else if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        throw std::invalid_argument("impossible to count tg()");
                                    }
                                }
                                operand1 = tan(operand1*M_PI/180);
                                break;
                            case 'l': // ln
                                if (operand1 <= 0){
                                    throw std::invalid_argument("impossible to count ln()");
                                }
                                operand1 = log(operand1);
                                break;
                        }
                    }
                    else if(tempStr.size() == 3) { // cos, sin, ctg, log, abs
                        switch (tempStr[0]) {
                            case 's':  // sin
                                if ((int)round(operand1) % 180 == 0){
                                    if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                        operand1 = 0;
                                        break;
                                    }
                                }
                                operand1 = sin(operand1*M_PI/180);
                                break;
                            case 'l':  // log
                                if (operand1 <= 0){
                                    throw std::invalid_argument("impossible to count lg()");
                                }
                                operand1 = log10(operand1);
                                break;
                            case 'a': // abs
                                operand1 = fabs(operand1);
                                break;
                            case 'c':
                                switch (tempStr[1]) {
                                    case 'o':  // cos
                                        if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                operand1 = 0;
                                                break;
                                            }
                                        }
                                        operand1 = cos(operand1*M_PI/180);
                                        break;
                                    case 't':  // ctg
                                        if ( ((int)round(operand1) % 90 == 0) && ((int)round(operand1) % 180 != 0) ){
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                operand1 = 0;
                                                break;
                                            }
                                        }
                                        else if ((int)round(operand1) % 180 == 0) {
                                            if (approximatelyEqual(operand1,round(operand1),0.00001)){
                                                throw std::invalid_argument("impossible to count ctg()");
                                            }
                                        }
                                        operand1 = 1 / tan(operand1*M_PI/180);
                                        break;
                                }
                                break;
                        }
                    }
                    else { // sqrt
                        if (operand1 < 0){
                            throw std::invalid_argument("impossible to count sqrt()");
                        }
                        operand1 = sqrt(operand1);
                    }
                    stackForCalculation.push(operand1);
                }
            }
        }
    }
    double result = stackForCalculation.getFront()->getData();
    stackForCalculation.pop();
    return result;
}

bool approximatelyEqual(double a, double b, double epsilon){
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

#endif //COURSEWORK_FUNCTIONS_CPP