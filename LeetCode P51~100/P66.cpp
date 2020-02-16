#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1]++;
		int tmp;
		for (int i = digits.size() - 1; i >= 0; i--) {
			tmp = digits[i] / 10;
			digits[i] %= 10;
			if (i != 0) digits[i - 1] += tmp;
			else if (tmp) digits.insert(digits.begin(), tmp);
		}
		return digits;
	}
};
int main() {
	Solution s = Solution();
	vector<int> num = { 9,9,9 };
	s.plusOne(num);
	for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
}