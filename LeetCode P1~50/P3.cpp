#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> HashMap(256, -1);
		int longest = 0, pos = 0;
		for (int i = 0; i < s.length(); i++) {
			pos = (pos > (HashMap[s[i]] + 1)) ? pos : (HashMap[s[i]] + 1);
			HashMap[s[i]] = i;
			longest = (longest > (i - pos + 1)) ? longest : (i - pos + 1);
		}
		return longest;
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	cout << s.lengthOfLongestSubstring(str);
}
#endif // DEBUG
