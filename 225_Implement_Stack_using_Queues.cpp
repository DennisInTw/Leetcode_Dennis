class MyStack {
public:
    // 用一個queue來模擬stack
    queue<int> que;
    
    MyStack() {
        
    }
    
    // 直接將x加入到que
    void push(int x) {
        que.push(x);    
    }
    
    int pop() {
        int val;
        int size = que.size();
        
        // 將que的前面元素都放到que的最後, 然後再移除元素, 一直到一開始的que的最後一個元素
        while (size-- > 1) {
            que.push(que.front());
            que.pop();
        }
        
        // que的front就是當初的最後一個元素
        val = que.front();
        que.pop();
        return val;
    }
    
    int top() {
        // que最後一個元素就是stack的top
        return que.back();
    }
    
    bool empty() {
        return que.empty();
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
