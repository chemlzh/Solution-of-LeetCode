#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<int>> ans;
	vector <int> tmp, nums1;
	map<int, int> vis;
	inline void dfs(int dep, int bound, int maxd) {
		if (dep == maxd) { ans.push_back(tmp);  return; }
		for (int i = bound; i < nums1.size(); i++) {
			if (vis[nums1[i]]) {
				tmp.push_back(nums1[i]), vis[nums1[i]]--;
				dfs(dep + 1, (vis[nums1[i]]) ? i : (i + 1), maxd);
				tmp.pop_back(), vis[nums1[i]]++;
			}
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (!vis[nums[i]]) nums1.push_back(nums[i]);
			vis[nums[i]]++;
		}
		for (int i = 0; i <= nums.size(); i++) dfs(0, 0, i);
		return ans;
	}
};
int main() {
	vector <int> v = { 1,1,2,2 };
	vector <vector<int>> ans;
	Solution s = Solution();
	ans = s.subsetsWithDup(v);
}