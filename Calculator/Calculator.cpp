#include "Header.h"

void Calculator::setResult(int value) {
    result = value;
};
int Calculator::getResult() const {
    return result;
};
int Calculator::calculate(char op, int firstNumber, int secondNumber) {
    if (op == '+' || op == '-' || op == '*' || op == '/') {
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
    }else {
        throw invalidOperatorException();
    };
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
Calculator& Calculator::operator+(int value) {
    this->result += value;
    return *this;
};
Calculator& Calculator::operator-(int value) {
    this->result -= value;
	return *this;
};
Calculator& Calculator::operator/(int value) {
    if (value == 0) {
        throw devidedByZeroException();
    }
    this->result /= value;
    return *this;
};
Calculator& Calculator::operator*(int value) {
    this->result *= value;
    return *this;
};
Calculator& Calculator::calculate(const char& op, const int& value)
{
    if (op == '+' || op == '-' || op == '*' || op == '/') {
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
    }
    else {
        throw invalidOperatorException();
	}
    return *this;
};