#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int count = 0, col = 0, diag1 = 0, diag2 = 0, maxStep;
	void dfs(int step) {
		if (step == maxStep) count++;
		else {
			for (int i = 0; i < maxStep; i++) {
				if ((((col >> i) & 1) == 0) && (((diag1 >> (step + i)) & 1) == 0) && (((diag2 >> (step - i + maxStep - 1)) & 1) == 0)) {
					col |= 1 << i, diag1 |= 1 << (step + i), diag2 |= 1 << (step - i + maxStep - 1);
					dfs(step + 1);
					col &= ~(1 << i), diag1 &= ~(1 << (step + i)), diag2 &= ~(1 << (step - i + maxStep - 1));
				}
			}
		}
	}
	int totalNQueens(int n) {
		maxStep = n, dfs(0);
		return count;
	}
};
#ifdef DEBUG
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.totalNQueens(n);
}
#endif // DEBUG