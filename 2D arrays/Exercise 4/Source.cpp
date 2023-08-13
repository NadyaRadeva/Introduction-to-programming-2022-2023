#include<iostream>

int maxRow(int** matrix, int n) {
	int max = INT_MAX, sum, maxRow;

	for (size_t i = 0; i < n; ++i) {
		sum = 0;
		for (size_t j = 0; j < n; ++j) {
			sum += matrix[i][j];
		}

		if (sum > max) {
			maxRow = i;
			max = sum;
		}
	}

	return max;
}

int maxCol(int** matrix, int n) {
	int max = INT_MAX, sum, maxCol;

	for (size_t i = 0; i < n; ++i) {
		sum = 0;
		for (size_t j = 0; j < n; ++j) {
			sum += matrix[j][i];
		}
		if (sum > max) {
			maxCol = i;
			max = sum;
		}
	}

	return max;
}

int main() {
	std::cout << "Enter size of the array: ";
	int n;
	std::cin >> n;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (n < 3 || n>32) {
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

	std::cout << "Max column: " << maxCol(matrix, n) << std::endl;
	std::cout << "Max row: " << maxRow(matrix, n) << std::endl;

	for (size_t i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 1;
}