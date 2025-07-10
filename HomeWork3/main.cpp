#include <iostream>
#include <typeinfo>
#include <limits>
void intExampleFunction(){
    std::cout << "Int examples: >>>>>>>>>>" << std::endl;

    int example1 = -5;
    std::cout << "Type of example1: " << typeid(example1).name() << std::endl;
    std::cout << "Size of example1: " << sizeof(example1) << std::endl;
    std::cout << "Max value of int: "
              << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Min value of int: " 
              << std::numeric_limits<int>::min() << std::endl;

    unsigned int example2 = -5;
    std::cout << "Type of example2: " << typeid(example2).name() << std::endl;
    std::cout << "Size of example2: " << sizeof(example2) << std::endl;
    std::cout << "Max value of unsigned int: "
              << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Min value of unsigned int: " 
              << std::numeric_limits<unsigned int>::min() << std::endl;

    signed int example3 = -5;
    std::cout << "Type of example3: " << typeid(example3).name() << std::endl;
    std::cout << "Size of example3: " << sizeof(example3) << std::endl;
    std::cout << "Max value of signed int: "
              << std::numeric_limits<signed int>::max() << std::endl;
    std::cout << "Min value of signed int: " 
              << std::numeric_limits<signed int>::min() << std::endl;

}
void shortExampleFunction(){
    std::cout << "Short examples: >>>>>>>>>>>>" << std::endl;

    short example1 = -5;
    std::cout << "Type of example1: " << typeid(example1).name() << std::endl;
    std::cout << "Size of example1: " << sizeof(example1) << std::endl;
    std::cout << "Max value of short: "
              << std::numeric_limits<short>::max() << std::endl;
    std::cout << "Min value of short: " 
              << std::numeric_limits<short>::min() << std::endl;

    unsigned short example2 = -5;
    std::cout << "Type of example2: " << typeid(example2).name() << std::endl;
    std::cout << "Size of example2: " << sizeof(example2) << std::endl;
    std::cout << "Max value of unsigned short: "
              << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "Min value of unsigned short: " 
              << std::numeric_limits<unsigned short>::min() << std::endl;

    signed short example3 = -5;
    std::cout << "Type of example3: " << typeid(example3).name() << std::endl;
    std::cout << "Size of example3: " << sizeof(example3) << std::endl;
    std::cout << "Max value of signed short: "
              << std::numeric_limits<signed short>::max() << std::endl;
    std::cout << "Min value of signed short: " 
              << std::numeric_limits<signed short>::min() << std::endl;
}
void shortIntExampleFunction(){
    std::cout << "ShortInt examples: >>>>>>>>>>>>>" << std::endl;

    short int example1 = -5;
    std::cout << "Type of example1: " << typeid(example1).name() << std::endl;
    std::cout << "Size of example1: " << sizeof(example1) << std::endl;
    std::cout << "Max value of short int: "
              << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "Min value of short int: " 
              << std::numeric_limits<short int>::min() << std::endl;

    unsigned short int example2 = -5;
    std::cout << "Type of example2: " << typeid(example2).name() << std::endl;
    std::cout << "Size of example2: " << sizeof(example2) << std::endl;
    std::cout << "Max value of unsigned short int: "
              << std::numeric_limits<unsigned short int>::max() << std::endl;
    std::cout << "Min value of unsigned short int: " 
              << std::numeric_limits<unsigned short int>::min() << std::endl;

    signed short int example3 = -5;
    std::cout << "Type of example3: " << typeid(example3).name() << std::endl;
    std::cout << "Size of example3: " << sizeof(example3) << std::endl;
    std::cout << "Max value of signed short int: "
              << std::numeric_limits<signed short int>::max() << std::endl;
    std::cout << "Min value of signed short int: " 
              << std::numeric_limits<signed short int>::min() << std::endl;
}
void longExampleFunction(){
    std::cout << "Long examples: >>>>>>>>>>>>>" << std::endl;

    long example1 = -5;
    std::cout << "Type of example1: " << typeid(example1).name() << std::endl;
    std::cout << "Size of example1: " << sizeof(example1) << std::endl;
    std::cout << "Max value of long: "
              << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Min value of long: " 
              << std::numeric_limits<long>::min() << std::endl;

    unsigned long example2 = -5;
    std::cout << "Type of example2: " << typeid(example2).name() << std::endl;
    std::cout << "Size of example2: " << sizeof(example2) << std::endl;
    std::cout << "Max value of unsigned long: "
              << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "Min value of unsigned long: " 
              << std::numeric_limits<unsigned long>::min() << std::endl;

    signed long example3 = -5;
    std::cout << "Type of example3: " << typeid(example3).name() << std::endl;
    std::cout << "Size of example3: " << sizeof(example3) << std::endl;
    std::cout << "Max value of signed long: "
              << std::numeric_limits<signed long>::max() << std::endl;
    std::cout << "Min value of signed long: " 
              << std::numeric_limits<signed long>::min() << std::endl;
}
void longIntExampleFunction(){
    std::cout << "Long int examples: >>>>>>>>>>>>>>>" << std::endl;
    long int example = 4;
    std::cout << "Type of example: " << typeid(example).name() << std::endl;
    std::cout << "Size of example: " << sizeof(example) << std::endl;
    std::cout << "Max value of long int: "
              << std::numeric_limits<long int>::max() << std::endl;
    std::cout << "Min value of long int: " 
              << std::numeric_limits<long int>::min() << std::endl;
}
void unsignedExampleFunction(){
    std::cout << "Unsigned examples: >>>>>>>>>>" << std::endl;
    unsigned example = -5;
    std::cout << "Type of example: " << typeid(example).name() << std::endl;
    std::cout << "Size of example: " << sizeof(example) << std::endl;
    std::cout << "Max value of unsigned: "
              << std::numeric_limits<unsigned>::max() << std::endl;
    std::cout << "Min value of unsigned: " 
              << std::numeric_limits<unsigned>::min() << std::endl;
}
void floatExampleFunction(){
    std::cout << "Float int examples: >>>>>>>>>>>>" << std::endl;
    float example = 5.2;
    std::cout << "Type of example: " << typeid(example).name() << std::endl;
    std::cout << "Size of example: " << sizeof(example) << std::endl;
    std::cout << "Max value of float: "
              << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Min value of float: " 
              << std::numeric_limits<float>::min() << std::endl;
}
void doubleExampleFunction(){
    std::cout << "Double int examples: >>>>>>>>>>>>>>>" << std::endl;
    double example = 5.2;
    std::cout << "Type of example: " << typeid(example).name() << std::endl;
    std::cout << "Size of example: " << sizeof(example) << std::endl;
    std::cout << "Max value of double: "
              << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Min value of double: " 
              << std::numeric_limits<double>::min() << std::endl;
}
void boolExampleFunction(){
    std::cout << "Boolean int examples: >>>>>>>>>>>>>>>" << std::endl;
    bool isExample = true;
    std::cout << "Type of isExample: " << typeid(isExample).name() << std::endl;
    std::cout << "Size of isExample: " << sizeof(isExample) << std::endl;
    std::cout << "Max value of boolean: "
              << std::numeric_limits<bool>::max() << std::endl;
    std::cout << "Min value of boolean: " 
              << std::numeric_limits<bool>::min() << std::endl;
}
int main(){
    intExampleFunction();
    shortExampleFunction();
    shortIntExampleFunction();
    longExampleFunction();
    longIntExampleFunction();
    unsignedExampleFunction();
    floatExampleFunction();
    doubleExampleFunction();
    boolExampleFunction();
}
