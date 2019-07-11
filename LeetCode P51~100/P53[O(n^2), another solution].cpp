#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = -0x7fffffff, sum, cnt = nums.size();
		for (int i = 0; i < cnt; i++) {
			sum = 0;
			for (int j = i; j < cnt; j++) sum += nums[j], ans = (ans > sum) ? ans : sum;
		}
		return ans;
	}
};
#ifdef DEBUG
int main() {
	vector v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution s = Solution();
	cout << s.maxSubArray(v);
}
#endif // DEBUG
