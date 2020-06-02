#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (!obstacleGrid.size()) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> f(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			if (!obstacleGrid[0][i]) f[0][i] = 1; else break;
		}
		for (int i = 0; i < m; i++) {
			if (!obstacleGrid[i][0]) f[i][0] = 1; else break;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (!obstacleGrid[i][j]) f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
		return f[m - 1][n - 1];
	}
};
int main() {
	vector<vector<int>> v = { {0,0,0},{0,1,0},{0,0,0} };
	Solution s = Solution();
	printf("%ld", s.uniquePathsWithObstacles(v));
}