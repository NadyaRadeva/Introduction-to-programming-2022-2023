#include<iostream>

const int MAX_SIZE = 100;

int main() {
	int n;
	std::cout << "Enter size of the array: ";
	std::cin >> n;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
		return 1;
	}
	if (n <= 0 || n > MAX_SIZE) {
		std::cout << "Invalid input!" << std::endl;
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	//извеждане на елементите под главния диагонал, включително и тези в него
	std::cout << "Elements in and under the main diagonal: ";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i >= j) {
				std::cout << matrix[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//извеждане на елементите над главния диагонал
	std::cout << "Elements above the main diagonal: ";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i < j) {
				std::cout << matrix[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//под второстепенния диагонал
	std::cout << "Elements below the secondary diagonal: ";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i > n - j - 1) {
				std::cout << matrix[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//над второстепенния, с елементите по него
	std::cout << "Elements above and in the secondary diagonal: ";
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			if (i <= n - j - 1) {
				std::cout << matrix[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for(int i = 0; i < n; i++) {
        delete[] matrix[i]
        }
	
        delete[] matrix;
}
