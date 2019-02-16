#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<char> v;
		string res = "";
		const int len = s.length(), l = (numRows - 1) << 1;
		int tmp = 0;
		for (long i = 0; i < len; i += l) v.push_back(s[i]);
		for (long i = 1; i < numRows - 1; i++) {
			for (long j = 0; (j + i) < len; j += l) {
				v.push_back(s[j + i]);
				if (j + l - i < len) v.push_back(s[j + l - i]);
			}
		}
		for (long i = l >> 1; i < len; i += l) v.push_back(s[i]);
		for (long i = 0; i < len; i++) res += v[i];
		return res;
	}
};
#ifdef DEBUG
int main() {
	string str = "A";
	int numRows = 1;
	Solution s = Solution();
	cout << s.convert(str, numRows);
}
#endif // DEBUG
