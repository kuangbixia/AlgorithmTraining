#include<iostream>
#include<stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node) {
    stack1.push(node);
}

int pop() {
    while (stack1.size() > 1) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    int popElement = stack1.top();
    stack1.pop();
    while (stack2.size()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
    return popElement;
}
  

int main() {

}