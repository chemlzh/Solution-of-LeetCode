#include <iostream>
#include <climits>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x == 0) return true;
		else {
			int rx = 0, y = x;
			while (y) {
				if (rx > (INT_MAX - y % 10) / 10) return false;
				rx = rx * 10 + y % 10, y /= 10;
			}
			return (rx == x) ? true : false;
		}
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
