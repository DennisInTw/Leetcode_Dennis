class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 雙指標法
        int slowIndex = 0;
        int fastIndex = 0;
        
        for (fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        
        return slowIndex;
    }
};
