#include "Header.h"

void Calculator::setResult(int value) {
    result = value;
};
int Calculator::getResult() const {
    return result;
};
int Calculator::calculate(char op, int firstNumber, int secondNumber) {
    if (op == '+') {
        return firstNumber + secondNumber;
    }
    else if (op == '-') {
        return firstNumber - secondNumber;
    }
    else if (op == '*') {
        return firstNumber * secondNumber;
    }
    else if (op == '/') {
        if (secondNumber == 0) {
            throw devidedByZeroException();
        }
        return firstNumber / secondNumber;
    }
    else {
        std::cerr << "Invalid operator." << std::endl;
    }
    return 0;
};
int Calculator::calculate(const char* op, const int* firstNumber, const int* secondNumber) {
    if (op && firstNumber && secondNumber)
        return calculate(*op, *firstNumber, *secondNumber);
};
int& Calculator::processFirstBy(const char op, int& firstNumber, const int secondNumber)
{
    firstNumber = calculate(op, firstNumber, secondNumber);
    return firstNumber;
};
Calculator& Calculator::calculate(const char& op, const int& value)
{
    if (op == '+') {
        int temp = result + value;
        setResult(temp);
    }
    else if (op == '-') {
        int temp = result - value;
        setResult(temp);
    }
    else if (op == '*') {
        int temp = result * value;
        setResult(temp);
    }
    else if (op == '/') {
        if (value == 0) {
            throw devidedByZeroException();
        }
        int temp = result / value;
        setResult(temp);
    }
    else {
        std::cerr << "Invalid operator." << std::endl;
    }
    return *this;
};