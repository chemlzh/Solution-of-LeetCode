#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr) {
			return (q == nullptr) ? true : false;
		}
		else {
			return (q == nullptr) ? false : 
				((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
	}
};
#ifdef DEBUG
TreeNode *buildTree(int num, vector<int> &v) {
	TreeNode *tmp;
	if (num > v.size()) tmp = nullptr;
	else tmp = new TreeNode(v[num - 1]), tmp->left = buildTree(num << 1, v), tmp->right = buildTree((num << 1) + 1, v);
	return tmp;
}
int main() {
	vector v1 = { 1,2,3 }, v2 = { 1,2,3 };
	Solution s = Solution();
	TreeNode *t1 = buildTree(1, v1), *t2 = buildTree(1, v2);
	cout << boolalpha << s.isSameTree(t1, t2);
}
#endif // DEBUG