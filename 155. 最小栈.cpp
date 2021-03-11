class MinStack {
private:
    stack<int> S;
    stack<int> min_S;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_S.push(INT_MAX);
    }
    
    void push(int x) {
        S.push(x);
        min_S.push(min(min_S.top(), x));
    }
    
    void pop() {
        S.pop();
        min_S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return min_S.top();
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