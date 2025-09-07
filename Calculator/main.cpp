#include "Header.h"
int main() {
    Calculator calc;
    int* firstNumber = new int;
    int* secondNumber = new int;
    char* op = new char;
    std::cout << "Enter first number: ";
    std::cin >> *firstNumber;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> *op;
    std::cout << "Enter second number: ";
    std::cin >> *secondNumber;

    int result = calc.calculate(*op, *firstNumber, *secondNumber);
    delete firstNumber;
    firstNumber = nullptr;
    delete secondNumber;
    secondNumber = nullptr;
    delete op;
    op = nullptr;
    std::cout << "Result: " << result << std::endl;
	
    int  first1 = 0;
    int second1 = 0;
    char op1 = 0;
    std::cout << "Enter first number: ";
    std::cin >> first1;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op1;
    std::cout << "Enter second number: ";
    std::cin >> second1;
    int res = calc.processFirstBy(op1, first1, second1);
    std::cout << "Result: " << res << std::endl;
    return 0;
}