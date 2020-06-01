#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <cctype>
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		int pos = 0, len = s.length(), depth = 0;
		string ans;
		stack<int> numStack;
		stack<pair<string, int>> stringStack;
		while (pos < len) {
			if (isdigit(s[pos])) {
				int num = 0;
				while (s[pos] != '[') num = num * 10 + s[pos] - '0', pos++;
				numStack.push(num), pos++, depth++;
			}
			else if (isalpha(s[pos])) {
				string tmpString = "";
				while (isalpha(s[pos])) tmpString += s[pos], pos++;
				stringStack.push(make_pair(tmpString, depth));
			}
			else if (s[pos] == ']') {
			//	pair<string, int> tmpPair = stringStack.top();
				string topString, tmpString;
				while ((!stringStack.empty()) && (stringStack.top().second == depth)) {
					topString = stringStack.top().first + topString, stringStack.pop();
				}
				int num = numStack.top();
				numStack.pop(), depth--;
				for (int i = 0; i < num; i++) tmpString += topString;
				stringStack.push(make_pair(tmpString, depth)), pos++;
			}
		}
		while (!stringStack.empty()) ans = stringStack.top().first + ans, stringStack.pop();
		return ans;
	}
};
int main() {
	string str = "3[a]2[bc]";
	Solution s = Solution();
	string ans = s.decodeString(str);
	cout << ans;
}