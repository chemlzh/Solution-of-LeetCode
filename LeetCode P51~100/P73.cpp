#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int cFlag = 0, rFlag = 0, cNum = matrix[0].size(), rNum = matrix.size();
		for (int i = 0; i < rNum; i++) 
			if (!matrix[i][0]) { cFlag = 1; break; }
		for (int j = 0; j < cNum; j++) 
			if (!matrix[0][j]) { rFlag = 1; break; }
		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[i].size(); j++) {
				if (!matrix[i][j]) matrix[i][0] = 0, matrix[0][j] = 0;
			}
		}
		for (int i = 1; i < rNum; i++)
			if (!matrix[i][0])
				for (int j = 0; j < cNum; j++) matrix[i][j] = 0;
		for (int j = 1; j < cNum; j++)
			if (!matrix[0][j])
				for (int i = 0; i < rNum; i++) matrix[i][j] = 0;
		if (cFlag)
			for (int i = 0; i < rNum; i++) matrix[i][0] = 0;
		if (rFlag)
			for (int j = 0; j < cNum; j++) matrix[0][j] = 0;
	}
};
int main() {
//	vector<vector<int>> v = { {1, 1, 1}, {1, 0, 1},	{1, 1, 1} };
	vector<vector<int>> v = { {0,1,2,0}, {3,4,5,2},{1,3,1,5} };
	Solution s = Solution();
	s.setZeroes(v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) cout << v[i][j] << " ";
		cout << endl;
	}
}