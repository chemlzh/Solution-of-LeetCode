#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//	vector<vector<int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (!matrix.size()) return res;
		int row = matrix.size(), col = matrix[0].size(), cycle = 0;
		int maxcycle = ((row > col) ? col : row) >> 1;
		while (cycle<maxcycle) {
			for (int i = cycle; i <= col - cycle - 2; i++) res.push_back(matrix[cycle][i]);
			for (int i = cycle; i <= row - cycle - 2; i++) res.push_back(matrix[i][col - cycle - 1]);
			for (int i = col - cycle - 1; i >= cycle + 1; i--) res.push_back(matrix[row - cycle - 1][i]);
			for (int i = row - cycle - 1; i >= cycle + 1; i--) res.push_back(matrix[i][cycle]);
			cycle++;
		}
		if ((row <= col) && (row % 2 == 1)) {
			for (int i = cycle; i <= col - cycle - 1; i++) res.push_back(matrix[cycle][i]);
		}
		else if ((row >= col) && (col % 2 == 1)) {
			for (int i = cycle; i <= row - cycle - 1; i++) res.push_back(matrix[i][cycle]);
		}
		return res;
	}
};
int main() {
	// vector<vector<int>> v = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	// vector<vector<int>> v = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	 vector<vector<int>> v = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	Solution s = Solution();
	vector<int> res = s.spiralOrder(v);
	for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
}