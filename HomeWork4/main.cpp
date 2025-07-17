#include <iostream>

int main() {
	int signedVar = -2;
	long int unsignedVar = -4294967294;

	unsigned long int result = signedVar + unsignedVar;

	std::cout << "Result of signedVar + max unsignedVar: " << result << std::endl;
	return 0;
}