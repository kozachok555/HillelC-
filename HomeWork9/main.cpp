#include "iostream"

int main(){
    std::cout << "Write the int number > 0 " << std::endl;
    unsigned sum = 0;
    unsigned value;
    std::cin >> value;
    while (value){
        sum += value % 10;
        if (value / 10 < 1 && value%10 == 0)
        {
            value /= 10;
            sum += value;
            value = 0;
        }
        value -= value % 10;
        value /= 10;
    }

    std::cout << sum << std::endl;
}