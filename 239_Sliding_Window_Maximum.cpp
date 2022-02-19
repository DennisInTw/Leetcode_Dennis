class Solution {
private :
    // MonotonicQueue為單調queue的類別
    class MonotonicQueue {
    public :
        // 建立deque
        deque<int> que;
        
        // 回傳最大值
        int front() {
            return que.front();
        }
        
        void pop(int val) {
            if (!que.empty() && val == que.front()) {
                que.pop_front();
            }
        }
        
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            
            que.push_back(val);
        }
    };
public:
    /* 使用單調queue (由大到小)來維護在sliding window的元素大小順序
       MonotonicQueue為單調queue的類別, 裡面實作以下內容 :
          1. front() : sliding window最大的元素都放在deque的front
          2. pop()   : 隨著sliding window移動會改變單調queue組成元素
                       不過只有在單調queue的front是sliding window即將要剃除的元素, 才會將單調queue的front移除
          3. push()  : 當sliding window移動時, 需要檢查單調queue裡的元素是否大於等於新的元素, 如果小於的話則要將單調queue的元素移除, 一直到調queue裡的元素大於等於新的元素
          
    
       這個單調queue有兩個特點 :
       1. 元素是由大到小排列好, 且單調queue元素相對順序和sliding window裡是相同的
          在單調queue裡的元素也存在sliding window裡, 第一個元素在第二個元素之前, 而且在sliding window裡順序也是如此
       2. 單調queue的front是sliding window裡的最大元素, 一直到sliding window即將移除的元素和queue的front相同時, queue才會將front移除
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue que;
        vector<int> ans;
        int len = nums.size();
        
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        
        // 放進第一個sliding window的最大值
        ans.push_back(que.front());
     
        // 將單調queue pop後才是push
        for (int i = k; i < len; i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            ans.push_back(que.front()); // 放進sliding window的最大值
        }

        return ans;
    }
};
