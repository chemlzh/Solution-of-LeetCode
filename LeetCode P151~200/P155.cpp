#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> v;
	int minVal = INT_MAX;
	MinStack() {}
	void push(int x) {
		minVal = ((!v.size()) || (minVal > x)) ? x : minVal;
		v.push_back(minVal);
		v.push_back(x);
	}
	void pop() {
		if (!v.empty()) {
			v.pop_back();
			v.pop_back();
			minVal = (v.empty()) ? INT_MAX : v[v.size() - 2];
		}
	}
	int top() {
		if (!v.empty()) return v[v.size() - 1];
		else return -1;
	}
	int getMin() {
		if (!v.empty()) return v[v.size() - 2];
		else return -1;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
	vector<string> op = { "MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin" };
	vector<int> num = { 0, 2147483646, 2147483646, 2147483647, 0, 0, 0, 0, 0, 0, 2147483647, 0, 0, -2147483648LL, 0, 0, 0, 0 };
	MinStack* obj = new MinStack();
	for (int i = 1; i < op.size(); i++) {
		if (op[i] == "push") obj->push(num[i]);
		else if (op[i] == "pop") obj->pop();
		else if (op[i] == "top") printf("top=%ld\n", obj->top());
		else if (op[i] == "getMin") printf("minNum=%ld\n", obj->getMin());
		else;
	}
}