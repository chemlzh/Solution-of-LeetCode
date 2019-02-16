#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x), rstr = str;
		reverse(rstr.begin(), rstr.end());
		return (str == rstr) ? true : false;
	}
};
#ifdef DEBUG
int main() {
	int x;
	cin >> x;
	Solution s = Solution();
	cout << boolalpha << s.isPalindrome(x);
}
#endif // DEBUG
