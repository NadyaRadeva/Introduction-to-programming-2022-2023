#include<iostream>

const unsigned int MAX_SIZE = 100;

bool even(unsigned int n) {
	return !(n % 2);
}

int matrixSum(unsigned int n, int** matrix) {
	int sum = 0;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i >= j) {
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

int main() {
	std::cout << "Enter the size of the array: ";
	int n;
	std::cin >> n;

	int** matrix = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		matrix[i] = new int[n];
	}

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << matrixSum(n, matrix) << std::endl;
	return 1;
}