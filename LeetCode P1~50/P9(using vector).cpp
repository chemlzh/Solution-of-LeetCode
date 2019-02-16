#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x == 0) return true;
		else {
			vector<int> v;
			int len = 0;
			while (x) v.push_back(x % 10), x /= 10, len++;
			for (int i = 0; i < len / 2; i++) {
				if (v[i] != v[len - i - 1]) return false;
			}
			return true;
		}
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
