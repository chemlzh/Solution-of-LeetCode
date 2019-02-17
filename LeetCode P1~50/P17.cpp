#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (!digits.length()) return res;
		vector<vector<char>> dic = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
										{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
		string tmp = "";
		dfs(res, dic, digits, tmp, 0);
		return res;
	}
	inline void dfs(vector<string> &res, vector<vector<char>> dic, string digits, 
							string &tmp, int depth) {
		if (depth == digits.length()) { res.push_back(tmp); return; }
		for (int i = 0; i < dic[digits[depth] - '2'].size(); i++) {
			tmp += dic[digits[depth] - '2'][i];
			dfs(res, dic, digits, tmp, depth + 1);
			tmp.pop_back();
		}
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	vector<string> ans = s.letterCombinations(str);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
#endif // DEBUG
