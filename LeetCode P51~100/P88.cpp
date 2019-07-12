#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m + n - 1;
		while ((m > 0) && (n > 0)) {
			if (nums1[m - 1] > nums2[n - 1]) nums1[pos] = nums1[m - 1], pos--, m--;
			else nums1[pos] = nums2[n - 1], pos--, n--;
		}
		while (m > 0) nums1[pos] = nums1[m - 1], pos--, m--;
		while (n > 0) nums1[pos] = nums2[n - 1], pos--, n--;
	}
};
#ifdef DEBUG
int main() {
	vector<int> v1 = { 1,2,3,0,0,0 }, v2 = { 2,5,6 };
	Solution s = Solution();
	s.merge(v1, 3, v2, 3);
	for (int i = 0; i < 3 + 3; i++) cout << v1[i] << ' ';
}
#endif // DEBUG