#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	inline double bfs(unordered_map<string, vector<pair<string, double>>> & g, string& s, string& t) {
		unordered_map<string, int> inq;
		queue < pair<string, double>> q;
		q.push({ s,1.0 });
		while (!q.empty()) {
			pair<string, double> tmp = q.front();
			q.pop();
			int i = 0, len = g[tmp.first].size();
			for (; i < len; i++) {
				if (g[tmp.first][i].first == t) return tmp.second * g[tmp.first][i].second;
				else if (!inq.count(g[tmp.first][i].first)) {
					inq[g[tmp.first][i].first] = 1;
					q.push({ g[tmp.first][i].first,tmp.second * g[tmp.first][i].second });
				}
			}
		}
		return -1.0;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, vector<pair<string, double>>> graph;
		int edgeCnt = equations.size(), queryCnt = queries.size();
		for (int i = 0; i < edgeCnt; i++) {
			graph[equations[i][0]].push_back({ equations[i][1], values[i] });
			graph[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
		}
		vector<double> res;
		for (int i = 0; i < queryCnt; i++) res.push_back(bfs(graph, queries[i][0], queries[i][1]));
		return res;
	}
};
int main() {
	vector<vector<string>> eq = { {"a","b"},{"b","c"} };
	vector<double> val = { 2.0,3.0 };
	vector<vector<string>> que = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };
	Solution s = Solution();
	vector<double> r = s.calcEquation(eq, val, que);
	for (int i = 0; i < r.size(); i++) printf("%f\n", r[i]);
}