#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
struct TreeNode {
	long long val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(long long x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	long long maxData = -(long long)2147483649;
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) return true;
		if (!isValidBST(root->left)) return false;
		if (root->val <= maxData) return false;
		maxData = root->val;
		if (!isValidBST(root->right)) return false;
		return true;
	}
};
#ifdef DEBUG
TreeNode* buildTree(long long num, vector<long long>& v) {
	TreeNode* tmp;
	if (num > v.size()) tmp = nullptr;
	else tmp = new TreeNode(v[num - 1]), tmp->left = buildTree(num << 1, v), tmp->right = buildTree((num << 1) + 1, v);
	return tmp;
}
int main() {
//	vector<long long> v = { 10,5,15,NULL,NULL,6,20 };
//	vector<long long> v = { 1,1 };
//	vector<long long> v = { 0 };
//	vector<long long> v = { 0, -1 };
	vector<long long> v = { -(long long)2147483648 };
	TreeNode* t = buildTree(1, v);
	Solution s = Solution();
	cout << boolalpha << s.isValidBST(t);
}
#endif // DEBUG