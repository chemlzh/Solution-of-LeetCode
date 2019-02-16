#include <iostream>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	string longestPalindrome(string s) {
		int h, t, MaxH = 0, MaxT = 0, MaxLen = 0, sLen = s.length();
		for (int i = 0; i < sLen;) {
			h = t = i;
			while ((t + 1 < sLen) && (s[t] == s[t + 1])) t++;
			i = t + 1;
			while ((h > 0) && (t + 1 < sLen) && s[h - 1] == s[t + 1]) h--, t++;
			if (MaxLen < t - h + 1) MaxLen = t - h + 1, MaxH = h, MaxT = t;
		}
		return s.substr(MaxH, MaxLen);
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	cout << s.longestPalindrome(str);
}
#endif // DEBUG
