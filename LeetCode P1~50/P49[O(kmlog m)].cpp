#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> anagramGroups;
		map<string, vector<string>>::iterator iter;
		for (int i = 0; i < strs.size(); i++) {
			string sortedWords = strs[i];
			sort(sortedWords.begin(), sortedWords.end());
			anagramGroups[sortedWords].push_back(strs[i]);
		}
		for (iter = anagramGroups.begin(); iter != anagramGroups.end(); iter++) {
			res.push_back(iter->second);
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