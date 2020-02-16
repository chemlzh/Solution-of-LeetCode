#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
	//O(k*m), but much slower because of transform function.
	inline string transform(string str) {
		vector<int> cnt(26, 0);
		for (int i = 0; i < str.length(); i++) cnt[str[i] - 'a']++;
		string trans = "";
		for (int i = 0; i < 26; i++) trans += to_string(cnt[i]) + '/';
		return trans;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> anagramGroups;
		map<string, vector<string>>::iterator iter;
		for (int i = 0; i < strs.size(); i++) {
			string transWords = transform(strs[i]);
			anagramGroups[transWords].emplace_back(strs[i]);
		}
		for (iter = anagramGroups.begin(); iter != anagramGroups.end(); iter++) {
			res.emplace_back(iter->second);
		}
		return res;
	}
};
int main() {
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution s = Solution();
	vector<vector<string>> result = s.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) cout << result[i][j] << ' ';
		cout << endl;
	}
}