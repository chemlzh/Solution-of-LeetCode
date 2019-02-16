#include <iostream>
#include <climits>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	int myAtoi(string str) {
		const int len = str.length();
		if (!len) return 0;
		bool flag = false;
		int pos = 0, ans = 0;
		while (str[pos] == ' ') pos++;
		if ((str[pos] == '+') || (str[pos] == '-')) {
			if (str[pos] == '-') flag = true;
			pos++;
		}
		if ((str[pos] >= '0') && (str[pos] <= '9')) {
			while ((str[pos] >= '0') && (str[pos] <= '9') && (pos < len)) {
				if (ans > (INT_MAX - (str[pos] - '0')) / 10) {
					if (flag) return INT_MIN;
					else return INT_MAX;
				}
				ans = ans * 10 + (str[pos] - '0'), pos++;	//Pay attention to the '()'!
			}
			if (flag) return (-ans);
			else return ans;
		}
		else return 0;
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	cout << s.myAtoi(str);
}
#endif // DEBUG
