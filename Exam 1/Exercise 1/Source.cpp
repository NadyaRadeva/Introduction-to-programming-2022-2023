#include<iostream>
#include<cmath>

//!Решето на Ератостен!

const int MAX_SIZE = 1024;

int main() {
	std::cout << "Enter a number: ";
	int numb;
	std::cin >> numb;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (numb <= 0 || numb > 1024) {
		std::cout << "Invalid input!" << std::endl;
		return 1;
	}

	bool isPrime[MAX_SIZE] = { false,false };

	for (size_t i = 2; i <= numb; ++i) {
		isPrime[i] = true;
	}

	for (size_t i = 2; i < sqrt(numb); ++i) {
		if (isPrime[i]) {
			for (size_t j = i * 2; j <= numb; j += i) {
				isPrime[i] = false;
			}
		}
	}

	int primeNumbs[MAX_SIZE], j = 0;
	for (size_t p = 2; p <= numb; p++) {
		if (isPrime[p]) {
			primeNumbs[j++] = p;
		}
	}

	for (size_t i = 0; i < j; ++i) {
		if (isPrime[i + 1]) {
			std::cout << primeNumbs[i] << " ";
		}
	}
	std::cout << std::endl;
}