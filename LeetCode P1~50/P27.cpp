#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int pos = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) nums[pos++] = nums[i];
		}
		return pos;
	}
};
#ifdef DEBUG
int main() {
	vector<int> v = { 0,1,2,2,3,0,4,2 };
	int val = 2, len;
	Solution s = Solution();
	len = s.removeElement(v, val);
	for (int i = 0; i < len; i++) cout << v[i] << ' ';
}
#endif // DEBUG
