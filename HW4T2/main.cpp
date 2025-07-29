#include <iostream>

int main() {
	int signedVar = -2;
	long long unsignedVar = -4294967294;

	long long result = signedVar + unsignedVar;

	std::cout << "Result of signedVar + max unsignedVar: " << unsignedVar << std::endl;
	return 0;
}