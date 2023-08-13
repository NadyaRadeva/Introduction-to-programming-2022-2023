#include<iostream>
#include<iomanip>

bool equalRings(int** matrix, int n, int& x) {
	x = -1;

	int innermostItem = matrix[n / 2 + 1][n / 2 + 1];

	for (size_t i = 0; i < n / 2; ++i) {
		int sum = 0;
        for (size_t j = i; j < n - i - 1; j++)
        {
            sum += matrix[i][j];
            sum += matrix[n - 1 - i][j];
            sum += matrix[j][i];
            sum += matrix[j][n - 1 - i];
        }
        if (innermostItem != sum)
        {
            x = i;
        }
	}

    return x != -1;
}

int main() {
    int n;
    std::cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int x;
    bool res = equalRings(matrix, n, x);
    std::cout << std::boolalpha << res << '\n';
    if (res)
    {
        printf("(%d,%d)\n", x, x);
    }

    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

