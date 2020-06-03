#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		/*
		vector<int> f = {0};
		for (int i = 1;; i++) {
			f.push_back(1);
			if (n == i * i) return f[n];
			for (int j = i * i + 1; j < (i + 1) * (i + 1); j++) {
				int minnum = 0x7fffffff;
				for (int k = 1; k <= (j + 1) / 2; k++) minnum = min(minnum, f[k] + f[j - k]);
				f.push_back(minnum);
				if (n == j) return f[n];
			}
		}
		*/
		vector<int> f = { 0,1,2,3,1 };
		for (int i = 5; i <= n; i++) {
			f.push_back(0x7fffffff);
			for (int j = 1; j * j <= i; j++) f[i] = min(f[i], 1 + f[i - j * j]);
		}
		return f[n];
	}
};
int main() {
	Solution s = Solution();
	printf("%ld", s.numSquares(8935));
}