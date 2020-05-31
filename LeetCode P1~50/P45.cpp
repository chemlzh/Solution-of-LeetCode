#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
/*
	int jump(vector<int>& nums) {
		int len = nums.size();
		vector<int> steps;
		steps.push_back(0);
		for (int i = 1; i < len; i++) {
			steps.push_back(i);
			for (int j = 0; j < i; j++) {
				if (j + nums[j] >= i) {
					steps[i] = (steps[i] > steps[j] + 1) ? (steps[j] + 1) : steps[i];
				}
			}
		}
		return steps[nums.size() - 1];
	}
*/
    int jump(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return 0;
		int stairs = nums[0], cover = nums[0], jump = 1;
		for (int pos = 1; pos < len; pos++) {
			if (pos == len - 1) return jump;
			if (cover < pos + nums[pos]) cover = pos + nums[pos];
			stairs--;
			if (!stairs) jump++, stairs = cover - pos;
		}
		return jump;
    }
};
int main() {
	vector<int> v = { 2,3,1,1,4 };
	Solution s = Solution();
	printf("%ld", s.jump(v));
}