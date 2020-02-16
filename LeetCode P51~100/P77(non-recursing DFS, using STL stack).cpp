#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> elem;
		if ((n == 0) || (k == 0) || (n < k)) return res;
		if (n == k) {
			for (int i = 1; i <= n; i++) elem.push_back(i);
			res.push_back(elem);
			return res;
		}
		stack<vector<int>> stk;
		for (int i = 1; i <= n; i++) stk.push({ i });
		vector<int> tmp;
		while (!stk.empty()) {
			elem = stk.top(), stk.pop();
			int len = elem.size();
			if (len == k) res.push_back(elem);
			else {
				tmp = elem, tmp.push_back(0);
				for (int i = elem[len - 1] + 1; i <= n; i++) tmp[len] = i, stk.push(tmp);
			}
		}
		return res;
	}
};
int main() {
	int N, K;
	cin >> N >> K;
	Solution s = Solution();
	vector<vector<int>> v = s.combine(N, K);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
		cout << endl;
	}
}