#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define DEBUG
class Solution {
public:
	int col = 0, diag1 = 0, diag2 = 0, maxStep;
	vector<vector<string>> answerSet;
	vector<string> answer;
	void dfs(int step) {
		if (step == maxStep) answerSet.push_back(answer);
		else {
			for (int i = 0; i < maxStep; i++) {
				if ((((col >> i) & 1) == 0) && (((diag1 >> (step + i)) & 1) == 0) && (((diag2 >> (step - i + maxStep - 1)) & 1) == 0)) {
					col |= 1 << i, diag1 |= 1 << (step + i), diag2 |= 1 << (step - i + maxStep - 1), answer[step][i] = 'Q';
					dfs(step + 1);
					col &= ~(1 << i), diag1 &= ~(1 << (step + i)), diag2 &= ~(1 << (step - i + maxStep - 1)), answer[step][i] = '.';
				}
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		for (int i = 0; i < n; i++) answer.push_back(string(n, '.'));
		maxStep = n, dfs(0);
		return answerSet;
	}
};
#ifdef DEBUG
void print(vector<vector<string>> answerSet) {
	for (int i = 0; i < answerSet.size(); i++) {
		for (int j = 0; j < answerSet[i].size(); j++) {
			for (int k = 0; k < answerSet[i][j].length(); k++) cout << answerSet[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
}
int main() {
	int n;
	vector<vector<string>> v;
	cin >> n;
	Solution s = Solution();
	v = s.solveNQueens(n);
	print(v);
}
#endif // DEBUG