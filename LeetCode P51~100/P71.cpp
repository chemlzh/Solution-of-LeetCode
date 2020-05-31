#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> s;
		string tmp, ans;
		int pos1 = 0, pos2, len = path.length();
		while (pos1 < len) {
			while ((pos1 < len) && (path[pos1] == '/')) pos1++;
			pos2 = pos1;
			while ((pos1 < len) && (path[pos1] != '/')) pos1++;
			if (pos2 < pos1) {
				tmp = path.substr(pos2, pos1 - pos2);
				if (tmp == "..") {
					if (!s.empty()) s.pop();
				}
				else if (tmp == ".");
				else s.push(tmp);
			}
		}
		if (s.empty()) return "/";
		while (!s.empty()) {
			ans = "/" + s.top() + ans;
			s.pop();
		}
		return ans;
	}
};
int main() {
	string pathName = "/a/../../b/../c//.//";
	Solution s = Solution();
	cout << s.simplifyPath(pathName);
}