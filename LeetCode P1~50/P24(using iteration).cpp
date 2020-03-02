#include <iostream>
#include <vector>
#define DEBUG
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* res = new ListNode(-1);
		res->next = head;
		ListNode* prev = res, * cur = head;
		while (cur && cur->next) {
			prev->next = cur->next;
			cur->next = cur->next->next;
			prev->next->next = cur;
			prev = cur, cur = cur->next;
		}
		return res->next;
	}
};
#ifdef DEBUG
inline void makeList(ListNode* &head, vector<int> v) {
	head = nullptr;
	ListNode* tmp = nullptr;
	for (int i = 0; i < v.size(); i++) {
		ListNode* newNode = new ListNode(v[i]);
		if (head == nullptr) head = newNode, tmp = newNode;
		else tmp->next = newNode, tmp = newNode;
	}
}
inline void printList(ListNode* head) {
	ListNode* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->val;
		if (tmp->next != nullptr) cout << "->";
		tmp = tmp->next;
	}
	cout << endl;
}
int main() {
	ListNode* listHead;
	vector<int> v = { 1,2,3,4 };
	makeList(listHead, v);
	printList(listHead);
	Solution s = Solution();
	listHead = s.swapPairs(listHead);
	printList(listHead);
}
#endif // DEBUG