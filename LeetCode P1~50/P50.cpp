#include <iostream>
#include <climits>
using namespace std;
#define DEBUG
class Solution {
public:
	double myPow(double x, int n) {
		return (n < 0) ? 1 / ((n == INT_MIN) ? QuickPow(x, -(n + 1))*x : QuickPow(x, -n)) : QuickPow(x, n);
	}
	inline double QuickPow(double x, int n) {
		if (!n) return 1.0;
		else if (n == 1) return x;
		double t = QuickPow(x, n >> 1);
		if (n & 1) return t * t*x;
		else return t * t;
	}
};
#ifdef DEBUG
#include <iomanip>
int main() {
	double x;
	int n;
	cin >> x >> n;
	Solution s = Solution();
	cout << fixed << setprecision(5) << s.myPow(x, n);
}
#endif // DEBUG

