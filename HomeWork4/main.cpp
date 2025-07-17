#include <iostream>

int calc(char op, int firstNumber, int secondNumber) {
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
            std::cout << "Cant devide by zero." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid operator." << std::endl;
    }
    return 0;
}

int main() {
    int firstNumber, secondNumber;
    char op;
    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;
    std::cout << "Enter second number: ";
    std::cin >> secondNumber;

    int result = calc(op, firstNumber, secondNumber);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
