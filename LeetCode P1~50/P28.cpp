#include <iostream>
#include <vector>
#include <string>
#define DEBUG
using namespace std;
class Solution {
public:
	void getFail(string needle, vector<int>& f) {
		int nlen = needle.length();
		f.push_back(0), f.push_back(0);		//f[0]=0,f[1]=0;
		for (int i = 1; i < nlen; i++) {
			int j = f[i];
			while (j && (needle[i] != needle[j])) j = f[j];
			f.push_back((needle[i] == needle[j]) ? (j + 1) : 0);
		}
	}
	int strStr(string haystack, string needle) {
		if (!needle.length()) return 0;
		else if (haystack.length() < needle.length()) return -1;
		vector<int> f;
		int hlen = haystack.length(), nlen = needle.length(), i, j = 0;
		getFail(needle, f);
		for (i = 0; i < hlen; i++) {
			while (j && (haystack[i] != needle[j])) j = f[j];
			if (haystack[i] == needle[j]) j++;
			if (j == nlen) return (i - nlen + 1);
		}
		return -1;
	}
};
#ifdef DEBUG
int main() {
	string haystack = "bbbbb", needle = "aab";
	Solution s = Solution();
	cout << s.strStr(haystack, needle);
}
#endif // DEBUG