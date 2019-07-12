#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int lengthOfLastWord(string s) {
		int pos = s.length() - 1, len = 0;
		while (s[pos] == ' ') pos--;
		while ((pos >= 0) && (s[pos] != ' ')) pos--, len++;
		return len;
	}
};
#ifdef DEBUG
#include <string>
int main() {
	string str = "hello world";
	Solution s = Solution();
	cout << s.lengthOfLastWord(str);
}
#endif // DEBUG