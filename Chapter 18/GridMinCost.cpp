#include <string>
#include <vector>
#include <iostream>

int min(int x, int y, int z) {
	x = std::min(x, y);
	return std::min(x, z);
}

int minCost(std::vector<std::vector<int>> &cost, int m, int n) {
	if (m == 0 || n == 0)
		return 9999;

	if(m == 1 && n == 1)
        return cost[0][0];

	return cost[m - 1][n - 1]
			+ min(minCost(cost, m - 1, n - 1), minCost(cost, m - 1, n),
					minCost(cost, m, n - 1));
}

int minCostBU(std::vector<std::vector<int>> &cost, int m, int n) {
	std::vector<std::vector<int>> tc = std::vector<std::vector<int>>(m,
			std::vector<int>(n, 0));
	tc[0][0] = cost[0][0];

	// Initialize first column.
	for (int i = 1; i < m; i++)
		tc[i][0] = tc[i - 1][0] + cost[i][0];

	// Initialize first row.
	for (int j = 1; j < n; j++)
		tc[0][j] = tc[0][j - 1] + cost[0][j];

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			tc[i][j] = cost[i][j]
					+ min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]);
		}
	}
	return tc[m - 1][n - 1];
}

// Testing code.
int main() {
	std::vector<std::vector<int>> cost =
			{ { 1, 3, 4 }, { 4, 7, 5 }, { 1, 5, 3 } };

	std::cout << minCost(cost, 3, 3) << std::endl;
	std::cout << minCostBU(cost, 3, 3) << std::endl;
}

/*
 11
 11
 */
