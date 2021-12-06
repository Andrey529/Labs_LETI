#ifndef COURSEWORK_FUNCTIONS_CPP
#define COURSEWORK_FUNCTIONS_CPP

#include "../../headers/functions/functions.h"

void inputExpression(std::string *expression){
    getline(std::cin, *expression);
}

bool priorityScale(std::string Operator1, std::string Operator2){
    if ( (Operator1 == "^") && ( (Operator2 == "*") || (Operator2 == "/") || (Operator2 == "+") || (Operator2 == "-")) )
        return true;
    if ( ((Operator1 == "*") || (Operator1 == "/")) && ((Operator2 == "+") || (Operator2 == "-")) )
        return true;
    else return false;
}

std::string convertInfixToPostfix(std::string expression) {
    stack<std::string> stackForOperators;
    std::string operands, functions, result;

    // remove spaces in string
    expression.erase(remove_if(expression.begin(), expression.end(), isspace), expression.end());

    for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {
        if ((*it) == '(') {
            stackForOperators.push(")"); // положить в стэк
        }
        else if ((*it) == ')') {

        }
        else if( (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.') ) {
            // добавить в конец выходного списка

            while ( (((*it) >= '0') && ((*it) <= '9')) || ((*it) == '.') ){

            }

            result.push_back(*it);
        }
        else if ( ((*it) >= 'a') && ((*it) <= 'z') ) {

        }
        else if ( ((*it) == '^') || ((*it) == '*') || ((*it) == '/') || ((*it) == '+') || ((*it) == '-') ) {
            if ( ((*it) == '^') && (stackForOperators.getFront()->getData() == "^") ) {
                if (!stackForOperators.isEmpty()){

                }
            }
            else if( (((*it) == '*') || ((*it) == '/')) && ( (stackForOperators.getFront()->getData() == "*")
                || (stackForOperators.getFront()->getData() == "/") || (stackForOperators.getFront()->getData() == "^")) ) {
                if (!stackForOperators.isEmpty()){

                }
            }
            else if ( ((*it) == '+') || ((*it) == '-') ) {
                if (stackForOperators.isEmpty()){
                    std::string push(1, *it);
                    stackForOperators.push(push);
                }
                else{
                    result.push_back("adc");
                }
            }
            else{
                std::string push(1, *it);
                stackForOperators.push(push);
            }
        }
    }


    return result;
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