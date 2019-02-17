#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;
#define DEBUG
class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m;
		m['I'] = 1, m['V'] = 5, m['X'] = 10, m['L'] = 50, m['C'] = 100, m['D'] = 500, m['M'] = 1000;
		int ans = 0, pos1 = 0, pos2 = 0, tmp1 = INT_MAX, tmp2;
		while (pos1 < s.length()) {
			tmp2 = 0;
			while ((pos2 < s.length()) && (s[pos2] == s[pos1])) tmp2 += m[s[pos1]], pos2++;
			ans += (tmp1 > tmp2) ? tmp2 : (tmp2 - 2 * tmp1), tmp1 = tmp2, pos1 = pos2;
		}
		return ans;
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	cout << s.romanToInt(str);
}
#endif // DEBUG
