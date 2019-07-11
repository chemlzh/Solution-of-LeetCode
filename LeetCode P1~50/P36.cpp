#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define DEBUG
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool digit[10];
		for (long i = 0; i < board.size(); i++) {
			memset(digit, 0, sizeof(digit));
			for (long j = 0; j < board.size(); j++) {
				if (board[i][j] == '.') continue;
				else if (digit[board[i][j] - '0']) return false;
				else digit[board[i][j] - '0'] = 1;
			}
			memset(digit, 0, sizeof(digit));
			for (long j = 0; j < board.size(); j++) {
				if (board[j][i] == '.') continue;
				else if (digit[board[j][i] - '0']) return false;
				else digit[board[j][i] - '0'] = 1;
			}
		}
		for (long x = 0; x < 9; x += 3) {
			for (long y = 0; y < 9; y += 3) {
				memset(digit, 0, sizeof(digit));
				for (long i = x; i <= x + 2; i++) {
					for (long j = y; j <= y + 2; j++) {
						if (board[i][j] == '.') continue;
						else if (digit[board[i][j] - '0']) return false;
						else digit[board[i][j] - '0'] = 1;
					}
				}
			}
		}
		return true;
	}
};
#ifdef DEBUG
int main() {
	vector<vector<char>> v = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	Solution s = Solution();
	cout << boolalpha << s.isValidSudoku(v);
}
#endif // DEBUG