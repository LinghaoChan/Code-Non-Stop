#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <stack> 
using namespace std;
class MinStack {
	stack<int> st;
	stack<int> stack_min;
public:
    /** initialize your data structure here. */
    MinStack():st(),stack_min(){
        stack_min.push(INT_MAX);
    }
    
    void push(int x) {
    	st.push(x);
        if(x<=stack_min.top()){
        	stack_min.push(x);
		}
    }
    
    void pop() {
        if(st.top() == stack_min.top()){
        	stack_min.pop();
		}
		st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stack_min.top();
    }
};

int main(){
	
	
	return 0;
} 
