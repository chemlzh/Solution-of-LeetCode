#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n) cnt += (n & 1), n >>= 1;
		return cnt;
	}
};
int main() {
	unsigned int n = 11;
	Solution s = Solution();
	printf("%ld", s.hammingWeight(n));
}