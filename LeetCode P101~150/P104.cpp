#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*treeRoot;
inline void makeTree(vector<int> treeArray, int num, TreeNode*& node) {
	if (num >= treeArray.size()) return;
	else if (treeArray[num] == NULL) return;
	TreeNode* tmpNode = new TreeNode(treeArray[num]);
	node = tmpNode;
	makeTree(treeArray, (num << 1) + 1, node->left);
	makeTree(treeArray, (num << 1) + 2, node->right);
}
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		else if ((root->left == NULL) && (root->right == NULL)) return 1;
		else {
			int ld = maxDepth(root->left), rd = maxDepth(root->right);
			return ((ld > rd) ? ld : rd) + 1;
		}
	}
};
int main() {
	vector<int> treeArray = { 3,9,20,NULL,NULL,15,7 };
	makeTree(treeArray, 0, treeRoot);
	Solution s = Solution();
	printf("Depth=%ld", s.maxDepth(treeRoot));
}