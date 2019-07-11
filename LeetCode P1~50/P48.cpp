#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		long tmp, maxr = matrix.size(), maxc = matrix[0].size();
		for (long i = 0; i < (maxr + 1) / 2; i++) {
			for (long j = 0; j < maxc / 2; j++) {
				tmp = matrix[i][j];
				matrix[i][j] = matrix[(maxc - 1 - j) % maxc][i];
				matrix[(maxc - 1 - j) % maxc][i] = matrix[(maxr - 1 - i) % maxr][(maxc - 1 - j) % maxc];
				matrix[(maxr - 1 - i) % maxr][(maxc - 1 - j) % maxc] = matrix[j][(maxr - 1 - i) % maxr];
				matrix[j][(maxr - 1 - i) % maxr] = tmp;
			}
		}
	}
};
#ifdef DEBUG
void print(vector<vector<int>>& matrix) {
	for (long i = 0; i < matrix.size(); i++) {
		for (long j = 0; j < matrix[i].size(); j++) cout << matrix[i][j] << ' ';
		cout << endl;
	}
}
int main() {
	vector<vector<int>> v = { {1,2,3},{4,5,6},{7,8,9} };
	//vector<vector<int>> v = { {5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16} };
	//vector<vector<int>> v = { {1} };
	print(v);
	cout << endl;
	Solution s = Solution();
	s.rotate(v);
	print(v);
}
#endif // DEBUG