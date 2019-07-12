#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int climbStairs(int n) {
		int pos = 3;
		vector<int> ans = { 1,1,2 };
		while (pos <= n) ans.push_back(ans[pos - 1] + ans[pos - 2]), pos++;
		return ans[n];
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