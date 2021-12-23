class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        int fastIndex = 0;
        
        for (fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        
        while (slowIndex < nums.size()) {
            nums[slowIndex++] = 0;
        }
    }
};
