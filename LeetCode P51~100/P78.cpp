#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> ans;
	vector <int> tmp;
	int* vis;
	inline void dfs(int dep, int bound, int maxd, vector<int>& nums) {
		if (dep == maxd) { ans.push_back(tmp);  return; }
		for (int i = bound; i < nums.size(); i++) {
			if (!vis[i]) {
				tmp.push_back(nums[i]), vis[i] = 1;
				dfs(dep + 1, i+1, maxd, nums);
				tmp.pop_back(), vis[i] = 0;
			}
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vis = new int [nums.size()];
		for (int i = 0; i < nums.size(); i++) vis[i] = 0;
		for (int i = 0; i <= nums.size(); i++) dfs(0, 0, i, nums);
		delete[] vis;
		return ans;
	}
};
int main() {
	vector <int> v = { 1,2,3 };
	vector <vector<int>> ans;
	Solution s = Solution();
	ans = s.subsets(v);
}