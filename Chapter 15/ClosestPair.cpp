#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

struct Point {
	int x = 0;
	int y = 0;

	Point(int a, int b) {
		x = a;
		y = b;
	}
};

double closestPairBF(std::vector<std::vector<int>> &arr) {
	int n = arr.size();
	double dmin = std::numeric_limits<double>::max();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			dmin = std::min(dmin,
					std::sqrt((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])
							+ (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1])));
		}
	}
	return dmin;
}


// Testing code.
int main() {
	std::vector<std::vector<int>> arr = { { 648, 896 }, { 269, 879 },
			{ 250, 922 }, { 453, 347 }, { 213, 17 } };
	std::cout << "Smallest distance is:" << closestPairBF(arr) << std::endl;
	return 0;
}

/*
 Smallest distance is:47.0106
 */
