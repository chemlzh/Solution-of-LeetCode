#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isValid(string s) {
		stack<char> ss;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}')) {
				if (ss.empty()) return false;
				if ((s[i] == ')') && (ss.top() == '(')) ss.pop();
				else if ((s[i] == ']') && (ss.top() == '[')) ss.pop();
				else if ((s[i] == '}') && (ss.top() == '{')) ss.pop();
				else return false;
			}
			else ss.push(s[i]);
		}
		return ss.empty();
	}
};
#ifdef DEBUG
int main() {
	string str;
	cin >> str;
	Solution s = Solution();
	cout << boolalpha << s.isValid(str);
}
#endif // DEBUG
