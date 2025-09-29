#include <iostream>
class  calculatorException: public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Some error";
    }
};
class devidedByZeroException : calculatorException {
public:
    virtual const char* what() const noexcept {
        return "Cant devide by zero";
    }
};
class invalidOperatorException : calculatorException {
    public:
    virtual const char* what() const noexcept {
        return "Invalid operator";
    }
};
class Calculator {
public:
    void setResult(int value);
    int getResult() const;
    int calculate(char op, int firstNumber, int secondNumber);
    int calculate(const char* op, const int* firstNumber, const int* secondNumber);
    int& processFirstBy(const char op, int& firstNumber, const int secondNumber);
    Calculator& operator+(int value);
    Calculator& operator-(int value);
    Calculator& operator/(int value);
    Calculator& operator*(int value);
    Calculator& calculate(const char& op, const int& value);

private:
    int result = 0;
};