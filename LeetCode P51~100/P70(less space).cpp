#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int climbStairs(int n) {
		int ans[4] = { 0,1,2,0 };
		if (n <= 2) return ans[n];
		else {
			int pos = 3;
			while (pos <= n) ans[3] = ans[2] + ans[1], ans[1] = ans[2], ans[2] = ans[3], pos++;
			return ans[2];
		}
	}
};
#ifdef DEBUG
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.climbStairs(n);
}
#endif // DEBUG