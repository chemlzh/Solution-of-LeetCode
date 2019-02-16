#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define DEBUG
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		int r, ans = 0;
		while (x) {
			r = (int)fabs(x % 10);
			if ((ans > (INT_MAX - r) / 10) || (ans < (INT_MIN + r) / 10)) return 0;
			ans = ans * 10 + x % 10, x /= 10;
		}
		return ans;
	}
};
#ifdef DEBUG
int main() {
	int x;
	cin >> x;
	Solution s = Solution();
	cout << s.reverse(x);
}
#endif // DEBUG
