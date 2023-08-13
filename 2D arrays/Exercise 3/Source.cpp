#include<iostream>

bool contains(int k, unsigned int n) {
	if (k < 0 || k>9) {
		return false;
	}
	while (n > 0) {
		if (n % 10 == k) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int product(int** matrix, unsigned int n) {
	int pr = 1;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (contains(1, matrix[i][j]) && i > n - 1 - j) {
				pr *= matrix[i][j];
			}
		}
	}

	return pr;
}

int main() {
	std::cout << "Enter size of the array: ";
	unsigned int n;
	std::cin >> n;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (n < 3 || n > 32) {
		std::cout << "Invalid input!" << std::endl;
		return 1;
	}

	int** matrix = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		matrix[i] = new int[n];
	}

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << product(matrix, n);

	for (size_t i = 0; i < n; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;

	return 1;
}