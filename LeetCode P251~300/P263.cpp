#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		else {
			while (num % 2 == 0) num /= 2;
			while (num % 3 == 0) num /= 3;
			while (num % 5 == 0) num /= 5;
			return (num > 1) ? false : true;
		}
	}
};
int main() {
	int number = 8;
	Solution s = Solution();
	printf("%s", (s.isUgly(number)) ? "true" : "false");
}