#include <iostream>
class devidedByZeroException : public std::exception {};
class Calculator {
public:
    void setResult(int value);
    int getResult() const;
    int calculate(char op, int firstNumber, int secondNumber);
    int calculate(const char* op, const int* firstNumber, const int* secondNumber);
    int& processFirstBy(const char op, int& firstNumber, const int secondNumber);
    Calculator& operator+(int value) {
        this->result += value;
    };
    Calculator& operator-(int value) {
        this->result -= value;
    };
    Calculator& operator/(int value) {
        if (value == 0) {
            throw devidedByZeroException();
        }
        this->result /= value;
    };
    Calculator& operator*(int value) {
        this->result *= value;
    };

    Calculator& calculate(const char& op, const int& value);

private:
    int result = 0;
};