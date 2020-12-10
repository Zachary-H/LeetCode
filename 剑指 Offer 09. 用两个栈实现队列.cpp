class CQueue {
public:
    stack<int> sta1;
    stack<int> sta2;


    CQueue() {

    }
    
    void appendTail(int value) {
        sta1.push(value);
    }
    
    int deleteHead() {
        if(sta1.empty()) return -1;

        while(!sta1.empty())
        {
            int tmp = sta1.top();
            sta1.pop();
            sta2.push(tmp);
        }

        int res = sta2.top();
        sta2.pop();

        while(!sta2.empty())
        {
            int tmp = sta2.top();
            sta2.pop();
            sta1.push(tmp);
        }

        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */