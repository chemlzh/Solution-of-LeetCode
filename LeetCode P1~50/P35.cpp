#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		if (target < nums[left]) return 0;
		if (target > nums[right]) return right + 1;
		while (left < right) {
			mid = (left + right) >> 1;
			if (nums[mid] >= target) right = mid;
			else left = mid + 1;
		}
		return left;
	}
};
#ifdef DEBUG
int main() {
	vector<int> v = { 1,3,5,6 };
	int target = 5;
	Solution s = Solution();
	cout << s.searchInsert(v, target);
	cout << endl;
	cout << lower_bound(v.begin(), v.end(), target) - v.begin()<< ' ' <<upper_bound(v.begin(), v.end(), target) - v.begin();
}
#endif // DEBUG