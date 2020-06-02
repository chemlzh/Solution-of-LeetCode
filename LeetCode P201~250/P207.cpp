#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	inline bool dfs(int vertex, unordered_map<int, vector<int>> &g, vector<int> &v) {
		v[vertex] = 0;
		int len = g[vertex].size();
		bool result = true;
		for (int i = 0; i < len; i++) {
			if (v[g[vertex][i]] == -1) result = result && dfs(g[vertex][i], g, v);
			else if (v[g[vertex][i]] == 0) return false;
		}
		v[vertex] = 1;
		return result;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int edgeCnt = prerequisites.size();
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < edgeCnt; i++) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		vector<int> vis(numCourses + 1, -1);
		bool result = true;
		for (int i = 0; i < numCourses; i++) {
			if (vis[i] != -1) continue;
			result = result && dfs(i, graph, vis);
		}
		return result;
	}
};
int main() {
	vector<vector<int>> edge = { {1,0},{0,1} };
	Solution s = Solution();
	printf("%s", (s.canFinish(2, edge)) ? "true" : "false");
}