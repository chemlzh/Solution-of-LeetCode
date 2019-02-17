/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
#define DEBUG
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if ((l1 == nullptr) && (l2 == nullptr)) return nullptr;
		else if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;
		else {
			ListNode* tmp = nullptr;
			//Note: this could be dangerous, since it may cause pointer dangling.
			if (l1->val <= l2->val) tmp = l1, l1 = l1->next;
			else tmp = l2, l2 = l2->next;
			tmp->next = mergeTwoLists(l1, l2);
			return tmp;
		}
	}
};
#ifdef DEBUG
#include <vector>
inline void Init(ListNode* &l, vector<int> v) {
	for (long i = v.size() - 1; i >= 0; i--) {
		ListNode *tmp = new ListNode(v[i]);
		if (l != nullptr) tmp->next = l;
		l = tmp;
	}
}
inline void Print(ListNode* l) {
	if (l == nullptr) { cout << 0; return; }
	while (l != nullptr) {
		cout << l->val;
		if (l->next != nullptr) cout << "->";
		l = l->next;
	}
}
int main() {
	vector<int> v1 = { 1,2,4 }, v2 = { 1,3,4 };
	ListNode *l1 = nullptr, *l2 = nullptr;
	Init(l1, v1), Init(l2, v2);
	Solution s = Solution();
	Print(s.mergeTwoLists(l1, l2));
}
#endif // DEBUG
