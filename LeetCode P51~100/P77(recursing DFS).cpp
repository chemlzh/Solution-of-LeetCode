#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	inline void DFS(int pos, int maxnum, int cnt, int tot, vector<int> &elem, vector<vector<int>> &res) {
		if (cnt == tot) res.push_back(elem);
		else {
			for (int i = pos + 1; i <= maxnum; i++) {
				elem.push_back(i);
				DFS(i, maxnum, cnt + 1, tot, elem, res);
				elem.pop_back();
			}
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> elem;
		if ((n == 0) || (k == 0) || (n < k)) return res;
		if (n == k) {
			for (int i = 1; i <= n; i++) elem.push_back(i);
			res.push_back(elem);
			return res;
		}
		DFS(0, n, 0, k, elem, res);
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