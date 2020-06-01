#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		int cnt = 0;
		long long ans = 1;
		priority_queue<long long, vector<long long>, greater<long long>> q;
		unordered_map<long long, int> vis;
		q.push(1);
		while (cnt < n) {
			ans = q.top(), q.pop(), cnt++;
			if (!vis[ans * 2]) q.push(ans * 2), vis[ans * 2] = 1;
			if (!vis[ans * 3]) q.push(ans * 3), vis[ans * 3] = 1;
			if (!vis[ans * 5]) q.push(ans * 5), vis[ans * 5] = 1;
		}
		return ans;
	}
};
int main() {
	Solution s = Solution();
	printf("%ld", s.nthUglyNumber(1407));
}