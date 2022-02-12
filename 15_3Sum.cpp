class Solution {
public:
    /* 
      
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        int left, right;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len; i++) {
            // 剪枝 : nums[i]大於0,就不可能有組合的總和為0
            if (nums[i] > 0) {
                return result;
            }
            
            // 剪枝 : 下一個元素和上一個相同時, 會組合出和上一個差不多的結果, 所以跳過
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            left = i + 1;
            right = len - 1;
            while (left < right) {
                
                // 避免相同組合的code不能寫在這裡, 不然[0, 0, 0]這個組合就不會考慮到 
                
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    
                    // 找到後需要移動left和right避免又產生相同組合

                    // --------------> 避免相同組合
                    
                    /* 向左搜尋到重複元素的第一個位置
                       例如 : -4, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 4
                       right會向左找到第一個4出現的位置(index = 8)
                    */
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    /* 向右搜尋到重複元素的最後一個位置
                       例如 : -4, 0, 0, 0, 0, 2, 2, 3, 4, 4, 4, 4
                       left會向右找到最後一個0出現的位置(index = 4)
                    */
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    
                    // <-------------- 避免相同組合
                    
                    // 得到和現在元素不同的值
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};15. 3Sum
