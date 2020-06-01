#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
}*ListHead;
class Solution {
public:
	bool hasCycle(ListNode* head) {		//Floyd cycle detection
		ListNode* fast = head, * slow = head;
		while ((fast != NULL) && (fast->next != NULL)) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};
inline void makeCycleList(ListNode*& Head, vector<int> v, int pos) {
	if (!v.size()) { Head = NULL; return; }
	else {
		Head = new ListNode(v[0]);
		ListNode* tmpNode = Head, * cycleNode = Head;
		for (int i = 1; i < v.size(); i++) {
			ListNode* newNode = new ListNode(v[i]);
			tmpNode->next = newNode;
			tmpNode = tmpNode->next;
			if (i == pos) cycleNode = tmpNode;
		}
		if (pos >= 0) tmpNode->next = cycleNode;
	}
}
int main() {
	vector<int> v = { 3,2,0,-4 };
	//makeCycleList(ListHead, v, 1);
	makeCycleList(ListHead, v, -1);
	Solution s = Solution();
	printf("%s", (s.hasCycle(ListHead)) ? "true" : "false");
}