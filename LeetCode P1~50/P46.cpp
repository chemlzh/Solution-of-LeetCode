#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> per, vis(nums.size(), 0);
		dfs(res, per, vis, nums, 0);
		return res;
	}
	inline void dfs(vector<vector<int>> &res, vector<int>& per, vector<int> &vis, 
							vector<int> nums, int depth) {
		if (depth == nums.size()) { res.push_back(per); return; }
		for (int i = 0; i < nums.size(); i++) {
			if (vis[i]) continue;
			vis[i] = 1, per.push_back(nums[i]);
			dfs(res, per, vis, nums, depth + 1);
			vis[i] = 0, per.pop_back();
		}
	}
};
#ifdef DEBUG
inline void Print(vector<vector<int>> res) {
	for (long i = 0; i < res.size(); i++) {
		for (long j = 0; j < res[i].size() - 1; j++) cout << res[i][j] << ",";
		cout << res[i][res[i].size() - 1] << endl;
	}
}
int main() {
	vector<int> v;
	int a;
	while ((cin >> a).eof()==false) v.push_back(a);
	Solution s = Solution();
	Print(s.permute(v));
}
#endif // DEBUG
