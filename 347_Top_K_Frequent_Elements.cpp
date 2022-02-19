class Solution {
public:
    // min-heap的比較
    class compare {
        public:
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            }
    };
    
    /* 統計好元素出現的次數, 再來對次數來做排序, 之後找出前k個最高次數的元素
    
       1. 統計元素出現次數 : unordered_map<int>
       2. 排序            : priority_queue(min-heap)對元素出現次數做出排序
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pri_que;
        int len = nums.size();
        unordered_map<int, int> umap;
        vector<int> ans(k);
        
        for (int i = 0; i < len; i++) {
            umap[nums[i]]++;
        }
        
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pri_que.top().first;
            pri_que.pop();
        }
        
        return ans;
    }
};
