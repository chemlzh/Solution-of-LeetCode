#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define DEBUG
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (long i = 0; i < nums.size(); i++) {
			if (m.count(target - nums[i])) return { m[target - nums[i]],i };
			m[nums[i]] = i;
		}
		return { 0,0 };
	}
};
#ifdef DEBUG
int main() {
	vector<int> numbers = { 3,2,4 };
	int target = 6;
	Solution s = Solution();
	cout << "[" << s.twoSum(numbers, target)[0] << ", " << s.twoSum(numbers, target)[1] << "]" << endl;
}
#endif // DEBUG