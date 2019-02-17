#include <iostream>
#include <map>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	string intToRoman(int num) {
		map<int, char> m = { {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'} };
		string str = "";
		for (int i = 1, j = num; j; i *= 10, j /= 10) {
			int tmp = j % 10;
			switch (tmp) {
			case 0: break;
			case 1: case 2: case 3: { str.insert(str.begin(), tmp, m[i]); break;  }
			case 4: {
				str.insert(str.begin(), m[i * 5]), str.insert(str.begin(), m[i]);
				break;
			}
			case 5: { str.insert(str.begin(), m[i * 5]); break;  }
			case 6: case 7: case 8: {
				str.insert(str.begin(), tmp - 5, m[i]);
				str.insert(str.begin(), m[i * 5]);
				break;
			}
			case 9: {
				str.insert(str.begin(), m[i * 10]);
				str.insert(str.begin(), 10 - tmp, m[i]);
				break;
			}
			}
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
