#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define DEBUG
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> per, element;
		map<int, int> cnt;
		for (int i = 0; i < nums.size(); i++) {
			if (!cnt[nums[i]]) element.push_back(nums[i]);
			cnt[nums[i]]++;
		}
		dfs(res, per, cnt, element, 0, element.size(), nums.size());
		return res;
	}
	inline void dfs(vector<vector<int>> &res, vector<int>& per, map<int, int> &cnt,
							vector<int> element, int depth, int maxe, int maxd) {
		if (depth == maxd) { res.push_back(per); return; }
		for (int i = 0; i < maxe; i++) {
			if (!cnt[element[i]]) continue;
			cnt[element[i]]--, per.push_back(element[i]);
			dfs(res, per, cnt, element, depth + 1, maxe, maxd);
			cnt[element[i]]++, per.pop_back();
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
	while ((cin >> a).eof() == false) v.push_back(a);
	Solution s = Solution();
	Print(s.permuteUnique(v));
}
#endif // DEBUG
