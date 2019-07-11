#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = -0x7fffffff, cnt = nums.size(), partSum = 0, minPartSum = 0;
		for (int i = 0; i < cnt; i++) {
			minPartSum = (partSum < minPartSum) ? partSum : minPartSum;
			partSum += nums[i];
			ans = (ans < (partSum - minPartSum)) ? partSum - minPartSum : ans;
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
