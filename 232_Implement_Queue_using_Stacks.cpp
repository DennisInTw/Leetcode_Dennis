class MyQueue {
public:
    /* 使用兩個stack來模擬Queue的操作
       stIn  : 輸入stack
       stOut : 輸出stack
    */
    stack<int> stIn;
    stack<int> stOut;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        
        int val = stOut.top();
        stOut.pop();
        return val;
    }
    
    // 直接用pop()作法
    int peek() {
        int val = this->pop();
        // 因為pop()將data移除, 所以需要再push()
        stOut.push(val);
        return val;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
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
