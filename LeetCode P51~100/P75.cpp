#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, len = nums.size() - 1, right = nums.size() - 1, pos;
		while ((left <= len - 1) && (nums[left] == 0)) left++;
		while ((right >= 0) && (nums[right] == 2)) right--;
		pos = left;
		while (pos <= right) {
			if (nums[pos] == 0) nums[pos++] = 1, nums[left++] = 0;
			else if (nums[pos] == 2) nums[pos] = nums[right], nums[right--] = 2;
			else pos++;
		}
	}
};
int main() {
	vector<int> colors = { 1 };
	Solution s = Solution();
	s.sortColors(colors);
	for (int i = 0; i < colors.size(); i++) cout << colors[i] << " ";
}