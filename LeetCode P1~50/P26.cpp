#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (!nums.size()) return 0;
		int cnt = 1, len = nums.size();
		for (int i = 1; i < len; i++) {
			if (nums[i] != nums[i - 1]) nums[cnt++] = nums[i];
		}
		return cnt;
	}
};
#ifdef DEBUG
int main() {
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	Solution s = Solution();
	int len = s.removeDuplicates(v);
	for (int i = 0; i < len; i++) cout << v[i] << ' ';
}
#endif // DEBUG
