#include<iostream>

void copyArray(int* arr1, int* arr2, int n) {
	for (size_t i = 0; i < n; ++i) {
		arr1[i] = arr2[i];
	}
}

void removeRow(int** matrix, int n, int m, int k) {
	for (int i = k; i < n - 1; ++i) {
		copyArray(matrix[i], matrix[i + 1], m);
	}

	delete[] matrix[n - 1];
}

void print(int** matrix, int n) {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++i) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Enter size of the array: ";
	int n;
	std::cin >> n;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (n <= 1 || n > 16) {
		std::cout << "Wrong numbers!" << std::endl;
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

	std::cout << "Enter a row to be erased: ";
	int m;
	std::cin >> m;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}

	removeRow(matrix, n, n, m);
	print(matrix, n - 1, n);
}