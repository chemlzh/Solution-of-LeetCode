#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> f(1, 1);
		int i2 = 0, i3 = 0, i5 = 0;
		while (f.size() < n) {
			int num2 = f[i2] * 2, num3 = f[i3] * 3, num5 = f[i5] * 5;
			int minnum = min(num2, min(num3, num5));
			if (minnum == num2) i2++;
			if (minnum == num3) i3++;		//Attention!
			if (minnum == num5) i5++;		//Attention!
			f.push_back(minnum);
		}
		return f.back();
	}
};
int main() {
	Solution s = Solution();
	printf("%ld", s.nthUglyNumber(1407));
}