#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (!triangle.size()) return 0;
		else if (triangle.size() == 1) return triangle[0][0];
		else {
			int len = triangle.size();
			for (int i = 1; i < len; i++) {
				triangle[i][0] += triangle[i - 1][0];
				triangle[i][i] += triangle[i - 1][i - 1];
				for (int j = 1; j < i; j++) triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
			int ans = 0x7fffffff;
			for (int i = 0; i < len; i++) ans = min(ans, triangle[len - 1][i]);
			return ans;
		}
	}
};
int main() {
	vector<vector<int>> t = { {2},{3,4},{6,5,7},{4,1,8,3} };
	Solution s = Solution();
	printf("%ld", s.minimumTotal(t));
}