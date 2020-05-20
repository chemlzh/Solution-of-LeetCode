#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int len = matrix.size(), row = 0, col = matrix[0].size() - 1;
		while ((row < len) && (col >= 0)) {
			if (matrix[row][col] == target) return true;
			else if (matrix[row][col] > target) col--;
			else row++;
		}
		return false;
	}
};
int main() {
//	vector<vector<int>> v = { {1, 3, 5, 7}, {10, 11, 16, 20}, 	{23, 30, 34, 50} };
	vector<vector<int>> v = {};
	Solution s = Solution();
	printf("%s", (s.searchMatrix(v, 13)) ? "true" : "false");
}