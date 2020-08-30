#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <stack> 
using namespace std;

class MyStack {
	deque<int> Stack;
public:
    /** Initialize your data structure here. */
    MyStack(): Stack({}) {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	Stack.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = top();
    	Stack.pop_back();
        return num;
    }
    
    /** Get the top element. */
    int top() {
    	return Stack.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    	return (Stack.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main(){
	cout<<"s";	
	return 0;
} 
