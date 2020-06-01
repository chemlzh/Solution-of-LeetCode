#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size(), pos = 0, ans = 0, low, high;
		while (pos < len - 1) {
			while ((pos < len - 1) && (prices[pos] >= prices[pos + 1])) pos++;
			low = prices[pos];
			while ((pos < len - 1) && (prices[pos] <= prices[pos + 1])) pos++;
			high = prices[pos];
			ans += high - low;
		}
		return ans;
	}
};
int main() {
	vector<int> v= {7, 1, 5, 3, 6, 4};
	Solution s = Solution();
	printf("%ld", s.maxProfit(v));
}