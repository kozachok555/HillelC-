
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

int main() {


    while (true) {
        std::string key, val;
        std::cout << "\n Enter name parametr";
        std::cin >> key;
        std::cout << "\n Enter new value";
        std::cin >> val;

        if (val == "0" || key == "0") {
            break;
        }
    }

    return 0;
}