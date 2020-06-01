#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> f = { 1 };
		for (int i = 1; i <= rowIndex; i++) {
			f.push_back(1);
			for (int j = f.size() - 2; j >= 1; j--) f[j] += f[j - 1];
		}
		return f;
	}
};
int main() {
	Solution s = Solution();
	vector<int> ans = s.getRow(1);
	for (int i = 0; i < ans.size(); i++) printf("%ld ", ans[i]);
}