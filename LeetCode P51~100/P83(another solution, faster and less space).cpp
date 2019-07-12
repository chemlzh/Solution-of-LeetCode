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
		ListNode* ansHead = head, * ans = head;
		head = head->next;
		while (head != nullptr) {
			if (ans->val != head->val) ans->next = head, ans = ans->next;
			head = head->next;
		}
		ans->next = nullptr;
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
	vector<int> v = { 1,1,2 };
	ListNode* l = nullptr;
	Init(l, v);
	Solution s = Solution();
	Print(s.deleteDuplicates(l));
}
#endif // DEBUG