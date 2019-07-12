#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if ((head == nullptr) || (head->next == nullptr)) return head;
		ListNode* ansHead, * ans;
		int value;
		value = head->val, ans = new ListNode(value), ansHead = ans, head = head->next;
		while (head != nullptr) {
			if (value != head->val) {
				ListNode* tmp = new ListNode(head->val);
				ans->next = tmp, ans = tmp;
			}
			value = head->val, head = head->next;
		}
		return ansHead;
	}
};
#ifdef DEBUG
inline void Init(ListNode*& l, vector<int> v) {
	for (int i = v.size() - 1; i >= 0; i--) {
		ListNode* tmp = new ListNode(v[i]);
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
	vector<int> v = { 1,1,2,3,3 };
	ListNode* l = nullptr;
	Init(l, v);
	Solution s = Solution();
	Print(s.deleteDuplicates(l));
}
#endif // DEBUG