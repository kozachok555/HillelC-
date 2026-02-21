#include "math.hpp"

extern "C" {
	int add(int a, int b) {
		return a + b;
	}
	int sub(int a, int b) {
		return a - b;
	}
	int mul(int a, int b) {
		return a * b;
	}
	int mydiv(int a, int b) {
		if (b == 0) return 0;
		return a / b;
	}
	int myfactorial(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		return n * myfactorial(n - 1);
	}
	int mylog(int n) {
		int result = 0;
		while (n > 1) {
			n /= 2;
			result++;
		}
		return result;
	}
	int mypow(int base, int exp) {
		int result = 1;
		for (int i = 0; i < exp; i++) {
			result *= base;
		}
		return result;
	}
	int mysqrt(int n) {
		int result = 0;
		while (result * result <= n) {
			result++;
		}
		return result - 1;
	}
}