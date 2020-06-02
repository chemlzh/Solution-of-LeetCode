#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int len1 = a.length(), len2 = b.length();
		int len = max(len1, len2);
		vector<int> v(len + 2, 0);
		for (int i = 0; i < len; i++) {
			if (len1 - 1 - i < 0) v[i] += b[len2 - 1 - i] - '0';
			else if (len2 - 1 - i < 0) v[i] += a[len1 - 1 - i] - '0';
			else v[i] += (a[len1 - 1 - i] - '0') + (b[len2 - 1 - i] - '0');
			v[i + 1] = v[i] / 2, v[i] %= 2;
		}
		len += 2;
		while ((len >= 1) && (!v[len - 1])) len--;
		if (!len) return "0";
		else {
			string ans = "";
			for (int i = len - 1; i >= 0; i--) ans += (v[i] + '0');
			return ans;
		}
	}
};
int main() {
	string s1 = "1", s2 = "0";
	Solution s = Solution();
	string ans = s.addBinary(s1, s2);
	cout << ans;
}