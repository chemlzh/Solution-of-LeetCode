#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int mySqrt(int x) {
		if ((x == 0) || (x == 1)) return x;
		int left = 0, right = x, ans = 0;
		while (left < right) {
			int mid = (left + right) / 2;
			if (mid == x / mid) { ans = mid; break; }
			else if (mid < x / mid) {
				if ((mid + 1) > x / (mid + 1)) { ans = mid; break; }
				else if ((mid + 1) == x / (mid + 1)) { ans = mid + 1; break; }
				else left = mid;
			}
			else right = mid;
		}
		return ans;
	}
};
#ifdef DEBUG
int main() {
	int x;
	cin >> x;
	Solution s = Solution();
	cout << s.mySqrt(x);
}
#endif // DEBUG