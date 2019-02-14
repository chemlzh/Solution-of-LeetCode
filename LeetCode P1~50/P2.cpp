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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if ((l1 == NULL) && (l2 == NULL)) return NULL;
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		int tmp = l1->val + l2->val;
		ListNode *l = new ListNode(tmp % 10);
		l->next = addTwoNumbers(l1->next, l2->next);
		if (tmp >= 10) l->next = addTwoNumbers(l->next, new ListNode(1));
		return l;
	}
};
#ifdef DEBUG
#include <vector>
ListNode *la, *lb;
inline void ConstructNumber(long num, ListNode* &l) {
	if (!num) { l = NULL; return; }
	vector<int> v;
	while (num) {
		v.push_back(num % 10);
		num /= 10;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		ListNode *tmp = new ListNode(v[i]);
		if (l == NULL) l = tmp;
		else tmp->next = l, l = tmp;
	}
}
inline void Print(ListNode* l) {
	if (l == NULL) { cout << 0; return; }
	while (l != NULL) {
		cout << l->val;
		if (l->next != NULL) cout << "->";
		l = l->next;
	}
}
int main() {
	long a, b;
	cin >> a >> b;
	ConstructNumber(a, la), ConstructNumber(b, lb);
	Solution s = Solution();
	Print(s.addTwoNumbers(la, lb));
}
#endif // DEBUG
