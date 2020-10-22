class MinStack {
private:
    stack<int> data_sta;
    stack<int> min_sta;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(min_sta.empty() || x < min_sta.top())
        {
            min_sta.push(x);
        }
        else
        {
            min_sta.push(min_sta.top());
        }
        data_sta.push(x);
    }
    
    void pop() {
        data_sta.pop();
        min_sta.pop();
    }
    
    int top() {
        return data_sta.top();
    }
    
    int min() {
        return min_sta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */