#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr) return nullptr;
		ListNode* node1 = head;
		ListNode* node2 = head;
		while (n) node1 = node1->next, n--;
		if (node1 == nullptr) return head->next;
		else {
			while (node1->next != nullptr) {
				node2 = node2->next, node1 = node1->next;
			}
			node2->next = node2->next->next;
			return head;
		}
	}
};
inline void makeList(ListNode*& head, vector<int> v) {
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
	listHead = s.removeNthFromEnd(listHead, 2);
	printList(listHead);
}