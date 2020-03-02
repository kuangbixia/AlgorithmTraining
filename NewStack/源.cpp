#include<iostream>
#include<stack>
using namespace std;

struct StackElement {
	int value;
	int nowMin;
	StackElement(int x, int y) :
		value(x), nowMin(y) {}
};

stack<StackElement>newStack;
void push(int value) {
	int nowMin;
	if (newStack.size()==0) {
		nowMin = value;
	}
	else {
		nowMin = value < newStack.top().nowMin ? value : newStack.top().nowMin;
	}
	StackElement e = StackElement(value, nowMin);
	newStack.push(e);
}
void pop() {
	newStack.pop();
}
int top() {
	return newStack.top().value;
}
int min() {
	return newStack.top().nowMin;
}

int main() {
	for (int i = 5; i >=0; i--) {
		push(i);
	}
	push(-1);
	cout << min() << endl;
	return 0;
	system("pause");
}