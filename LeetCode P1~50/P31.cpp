#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size(), i = len - 1, j = len - 1, tmp;
		for (; i > 0; i--) {
			if (nums[i] > nums[i - 1]) break;
		}
		if (!i) {
			for (int k = 0; k < len / 2; k++) {
				tmp = nums[k], nums[k] = nums[len - k - 1], nums[len - k - 1] = tmp;
			}
			return;
		}
		for (; j > i - 1; j--) {
			if (nums[j] > nums[i - 1]) break;
		}
		tmp = nums[j], nums[j] = nums[i - 1], nums[i - 1] = tmp;
		for (int k = 0; k < (len - i + 1) / 2; k++) {
			tmp = nums[i + k], nums[i + k] = nums[len - k - 1], nums[len - k - 1] = tmp;
		}
	}
};
int main() {
	vector<int> v1 = { 1,3,5,4,2 };
	for (int i = 0; i < v1.size(); i++) printf("%ld ", v1[i]);
	printf("\n");
	Solution s = Solution();
	s.nextPermutation(v1);
	for (int i = 0; i < v1.size(); i++) printf("%ld ", v1[i]);
}