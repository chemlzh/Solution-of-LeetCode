#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v;
		vector<int> f;
		if (!numRows) return v;
		f.push_back(1), v.push_back(f);
		if (numRows == 1) return v;
		else {
			for (int i = 2; i <= numRows; i++) {
				f.push_back(1);
				for (int j = f.size() - 2; j >= 1; j--) f[j] += f[j - 1];
				v.push_back(f);
			}
			return v;
		}
	}
};
int main() {
	Solution s = Solution();
	vector<vector<int>> ans = s.generate(5);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) printf("%ld ", ans[i][j]);
		printf("\n");
	}
}