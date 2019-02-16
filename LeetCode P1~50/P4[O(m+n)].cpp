#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int len = nums1.size() + nums2.size(), len1 = nums1.size(), len2 = nums2.size();
		int p1 = 0, p2 = 0, a1 = -1, a2 = -1, cnt = 0;
		while (p1 + p2 < len) {
			if (p1 < len1) {
				while ((p2 == len2) || (nums1[p1] <= nums2[p2])) {
					p1++;
					if (p1 + p2 == (len + 1) / 2) a1 = nums1[p1 - 1];
					if (p1 + p2 == (len + 2) / 2) {
						a2 = nums1[p1 - 1];
						return (a1 + a2)*1.0 / 2;
					}
					if (p1 == len1) break;
				}
			}
			if (p2 < len2) {
				while ((p1 == len1) || (nums2[p2] <= nums1[p1])) {
					p2++;
					if (p1 + p2 == (len + 1) / 2) a1 = nums2[p2 - 1];
					if (p1 + p2 == (len + 2) / 2) {
						a2 = nums2[p2 - 1];
						return (a1 + a2)*1.0 / 2;
					}
					if (p2 == len2) break;
				}
			}
		}
		return -1.0;
	}
};
#ifdef DEBUG
int main() {
	vector <int> n1 = { 1,3 }, n2 = { 2,4 };
	Solution s = Solution();
	cout << s.findMedianSortedArrays(n1, n2);
}
#endif // DEBUG
