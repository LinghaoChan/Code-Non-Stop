class MyQueue {
    stack<int> queue;
    stack<int> queue_help;
public:
    /** Initialize your data structure here. */
    MyQueue(): queue(), queue_help() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        queue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!queue.empty()){
            int tmp = queue.top();
            queue.pop();
            queue_help.push(tmp);
        }
        int finalnum = queue_help.top();
        queue_help.pop();
        while(!queue_help.empty()){
            int tmp = queue_help.top();
            queue_help.pop();
            queue.push(tmp);
        }
        return finalnum;
    }
    
    /** Get the front element. */
    int peek() {
        while(!queue.empty()){
            int tmp = queue.top();
            queue.pop();
            queue_help.push(tmp);
        }
        int finalnum = queue_help.top();
        while(!queue_help.empty()){
            int tmp = queue_help.top();
            queue_help.pop();
            queue.push(tmp);
        }
        return finalnum;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */