class MyStack {
public:
    // 用兩個queue來模擬stack
    queue<int> que1;
    queue<int> que2;
    
    MyStack() {
        
    }
    
    // 直接將x加入到que1
    void push(int x) {
        que1.push(x);    
    }
    
    int pop() {
        int val;
        int size = que1.size();
        
        // 將que1的元素(除了最後一個元素)移到que2
        while (size-- > 1) {
            que2.push(que1.front());
            que1.pop();
        }
        
        // que1只剩一個元素, 將他pop出來
        val = que1.front();
        que1.pop();
        
        // 再將que2元素移到que1
        while (!que2.empty()) {
            que1.push(que2.front());
            que2.pop();
        }
        return val;
    }
    
    int top() {
        // que1最後一個元素就是stack的top
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
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
