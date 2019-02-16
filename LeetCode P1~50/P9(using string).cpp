#include <iostream>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		const int len = str.length();
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - i - 1]) return false;
		}
		return true;
	}
};
#ifdef DEBUG
int main() {
	int x;
	cin >> x;
	Solution s = Solution();
	cout << boolalpha << s.isPalindrome(x);
}
#endif // DEBUG
