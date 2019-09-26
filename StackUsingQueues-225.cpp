class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    int topNum;
    MyStack() {
     
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topNum = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int val;
        while(q1.size() > 1) {
            val = q1.front();
            q1.pop();
            topNum = val;
            q2.push(val);
        }
        
        val = q1.front();
        q1.pop();
        swap(q1, q2);
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return topNum;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return q1.empty() && q2.empty(); 
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
