#include <string>
#include <vector>
#include <iostream>

int lbs(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<int> lis(n, 1); // Initialize LIS values for all indexes as 1.
	std::vector<int> lds(n, 1); // Initialize LDS values for all indexes as 1.
	int max = 0;

	// Populating LIS values in bottom up manner.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}

	// Populating LDS values in bottom up manner.
	for (int i = n - 1; i > 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
		}
	}

	for (int i = 0; i < n; i++)
		max = std::max(max, lis[i] + lds[i] - 1);
	return max;
}

// Testing code.
int main() {
	std::vector<int> arr = {1, 6, 3, 11, 1, 9, 5, 12, 3, 14, 6, 17, 3, 19, 2, 19};
	std::cout << "Length of lbs is " << lbs(arr) << std::endl;
}

/*
 Length of lbs is 8
 */
