#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size();
		vector<vector<int>> height(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			if (matrix[0][i] == '1') height[0][i] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') height[i][j] = 1 + height[i - 1][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int h = height[i][j];
				for (int k = j; k < n; k++) {
					h = min(h, height[i][k]), ans = max(ans, h * (k - j + 1));
				}
			}
		}
		return ans;
	}
};
int main() {
	vector<vector<char>> m = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'},
			{'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
	Solution s = Solution();
	printf("%ld", s.maximalRectangle(m));
}