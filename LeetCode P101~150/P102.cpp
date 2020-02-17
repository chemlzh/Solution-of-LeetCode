#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> tmp;
			int cnt = q.size();
			while (cnt--) {
				TreeNode* t = q.front();
				q.pop(), tmp.push_back(t->val);
				if (t->left != NULL) q.push(t->left);
				if (t->right != NULL) q.push(t->right);
			}
			res.push_back(tmp);
		}
		return res;
	}
};
int main() {
	vector<int> treeArray = { 3,9,20,NULL,NULL,15,7 };
	makeTree(treeArray, 0, treeRoot);
	Solution s = Solution();
	vector<vector<int>> ans = s.levelOrder(treeRoot);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << endl;
	}
}