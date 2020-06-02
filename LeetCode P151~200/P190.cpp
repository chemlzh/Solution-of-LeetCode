#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		if (!n) return 0;
		int length = 8 * sizeof(n);
		int ans = 0;
		for (; n != 0; n >>= 1) {
			ans <<= 1, ans |= (n & 1), length--;
		}
		ans <<= length;
		return ans;
	}
};
int main() {
	unsigned int u = 0;
	Solution s = Solution();
	printf("%lu", s.reverseBits(u));
}