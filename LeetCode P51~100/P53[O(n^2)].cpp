#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = -0x7fffffff, sum = 0, cnt = nums.size();
		vector<int> partSum;
		partSum.push_back(0);
		for (int i = 0; i < cnt; i++) sum += nums[i], partSum.push_back(sum);
		for (int i = 0; i < cnt; i++) {
			for (int j = i; j < cnt; j++) ans = (ans > (partSum[j + 1] - partSum[i])) ? ans : (partSum[j + 1] - partSum[i]);
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
