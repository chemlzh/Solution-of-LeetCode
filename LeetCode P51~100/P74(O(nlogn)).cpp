#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size(); i++) {
			int l = 0, r = matrix[i].size() - 1;
			while (l<=r) {
				int mid = l + ((r - l) >> 1);
				if (matrix[i][mid] < target) l = mid + 1;
				else if (matrix[i][mid] > target) r = mid - 1;
				else return true;
			}
		}
		return false;
	}
};
int main() {
	vector<vector<int>> v = { {1, 3, 5, 7}, {10, 11, 16, 20}, 	{23, 30, 34, 50} };
	Solution s = Solution();
	printf("%s", (s.searchMatrix(v, 13)) ? "true" : "false");
}