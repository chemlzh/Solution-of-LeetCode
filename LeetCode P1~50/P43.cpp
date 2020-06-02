#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length(), len2 = num2.length(), len = len1 + len2;
		vector<int> res(len1 + len2, 0);
		for (int i=len1-1;i>=0;i--) {
			for (int j = len2 - 1; j >= 0; j--) {
				res[len - (i + j + 2)] += (num1[i] - '0') * (num2[j] - '0');
				res[len - (i + j + 1)] += res[len - (i + j + 2)] / 10;
				res[len - (i + j + 2)] %= 10;
			}
		}
		while ((len > 0) && (!res[len - 1])) len--;
		if (!len) return "0";
		else {
			string ans = "";
			for (int i = len - 1; i >= 0; i--) ans += (res[i] + '0');
			return ans;
		}
	}
};
int main() {
	string n1 = "123", n2 = "456";
	Solution s = Solution();
	string ans = s.multiply(n1, n2);
	cout << ans;
}