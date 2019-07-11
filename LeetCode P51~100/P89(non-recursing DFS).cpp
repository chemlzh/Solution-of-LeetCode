#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define DEBUG
class Solution {
public:
	vector<int> vis, ans;
	vector<int> grayCode(int n) {
		for (int i = 0; i < (1 << n); i++) vis.push_back(0);
		stack<int> s;
		s.push(0);
		while (!s.empty()) {
			int num = s.top(), isOperated = 0;
			vis[num] = 1, ans.push_back(num), s.pop();
			for (int i = n - 1; i >= 0; i--) {
				num ^= 1 << i;
				if (!vis[num]) s.push(num), isOperated = 1;
				num ^= 1 << i;
			}
			if (!isOperated) break;
		}
		return ans;
	}
};
#ifdef DEBUG
int main() {
	int n;
	vector<int> v;
	cin >> n;
	Solution s = Solution();
	v = s.grayCode(n);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}
#endif // DEBUG