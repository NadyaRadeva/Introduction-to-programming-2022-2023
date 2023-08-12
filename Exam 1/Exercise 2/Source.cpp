#include<iostream>

const int base = 10;

int uniqueDigits(int number) {
	bool unique = true;

	while (unique && number) {
		int digit = number % base;
		int tmp = number /= base;

		while (tmp && digit != tmp % base) {
			tmp /= base;
		}

		unique = tmp == 0;
	}

	return unique;
}

int numberOfDigits(int number) {
	int count = 0;
	while (number) {
		number /= base;
		count++;
	}

	return count;
}

int main() {
	int q;
	std::cout << "Enter a number: ";
	std::cin >> q;
	if (!std::cin) {
		std::cout << "Error! Wrong input!" << std::endl;
	}

	for (size_t i = 0; i < q; ++i) {
		int n, m;
		std::cin >> n >> m;

		if (!(uniqueDigits(n) && uniqueDigits(m))) {
			std::cout << "Error. Numbers do not contain unique digits." << std::endl;
			continue;
		}

		if (numberOfDigits(n) != numberOfDigits(m)) {
			std::cout << "Error. Numbers are not the same count." << std::endl;
			continue;
		}

		int index = 0, matches = 0;
		while (n) {
			int digit = n % base, mCopy = m, mIndex = 0;
			while (mCopy) {
				if (mCopy % base == digit && mIndex != index) {
					matches;
					break;
				}
				mCopy /= base;
				mIndex++;
			}

			index++;
			n /= base;
		}

		std::cout << matches << std::endl;
	}
}