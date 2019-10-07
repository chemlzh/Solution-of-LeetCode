#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	struct element { long key, count; };
	vector<vector<int>> ans;
	vector <int> tmp;
	map<int, int> vis;
	inline void dfs(int dep, int bound, int maxd, vector<int>& nums) {
		if (dep == maxd) { ans.push_back(tmp);  return; }
		for (int i = bound; i < vis.size(); i++) {
			if (vis[nums[i]]) {
				tmp.push_back(nums[i]), vis[nums[i]] = 0;
				dfs(dep + 1, i + 1, maxd, nums);
				tmp.pop_back(), vis[nums[i]] = 1;
			}
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) vis[nums[i]] = 1;
		for (int i = 0; i <= nums.size(); i++) dfs(0, 0, i, nums);
		return ans;
	}
};
int main() {
	vector <int> v = { 1,2,3 };
	vector <vector<int>> ans;
	Solution s = Solution();
	ans = s.subsets(v);
}