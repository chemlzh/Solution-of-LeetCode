#include <iostream>
#include <map>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	string intToRoman(int num) {
		map<int, char> m = { {1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'},{500,'D'}, {1000,'M'} };
		string str = "";
		for (int i = 1000, tmp; i >= 1; i /= 10) {
			tmp = num / i, num %= i;
			if (!tmp) continue;
			else if ((tmp >= 1) && (tmp <= 3)) str.append(tmp, m[i]);
			else if (tmp == 4) str += m[i], str += m[i * 5];
			else if (tmp == 5) str += m[i * 5];
			else if ((tmp >= 6) && (tmp <= 8)) str += m[i * 5], str.append(tmp - 5, m[i]);
			else str += m[i], str += m[i * 10];
		}
		return str;
	}
};
#ifdef DEBUG
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.intToRoman(n);
}
#endif // DEBUG
