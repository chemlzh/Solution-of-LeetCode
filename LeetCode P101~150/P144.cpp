#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}*treeRoot;
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> s;
		if (root != nullptr) s.push(root);
		while (!s.empty()) {
			TreeNode* tempNode = s.top();
			s.pop();
			if (tempNode->right != nullptr) s.push(tempNode->right);
			if (tempNode->left != nullptr) s.push(tempNode->left);
			ans.push_back(tempNode->val);
		}
		return ans;
	}
};
inline void makeTree(vector<int> treeArray, int num, TreeNode*& node) {
	if (num >= treeArray.size()) return;
	else if (treeArray[num] == NULL) return;
	TreeNode* tmpNode = new TreeNode(treeArray[num]);
	node = tmpNode;
	makeTree(treeArray, (num << 1) + 1, node->left);
	makeTree(treeArray, (num << 1) + 2, node->right);
}
int main() {
//	vector<int> treeArray = { 1,NULL,2,NULL,NULL,3,NULL };
	vector<int> treeArray = {};
	makeTree(treeArray, 0, treeRoot);
	Solution s = Solution();
	vector<int> ans = s.preorderTraversal(treeRoot);
	for (int i = 0; i < ans.size(); i++) printf("%ld ", ans[i]);
}