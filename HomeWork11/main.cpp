#include <iostream>
int calculate(char op, int firstNumber, int secondNumber) {
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
        if (secondNumber != 0) {
            return firstNumber / secondNumber;
        }
        else {
            std::cout << "You cannot divide by 0";
            return 0;
        }
    }
    else {
        std::cerr << "Invalid operator." << std::endl;
    }
    return 0;
}
int calculate(const char* op, const int* firstNumber, const int* secondNumber) {
    if (op && firstNumber && secondNumber)
        return calculate(*op, *firstNumber *secondNumber);
}
int main() {
    int* firstNumber = new int;
    int* secondNumber = new int;
    char* op = new char;
    std::cout << "Enter first number: ";
    std::cin >> *firstNumber;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> *op;
    std::cout << "Enter second number: ";
    std::cin >> *secondNumber;

    int result = calculate(*op, *firstNumber, *secondNumber);
    delete firstNumber;
    firstNumber = nullptr;
    delete secondNumber;
    secondNumber = nullptr;
    delete op;
    op = nullptr;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
