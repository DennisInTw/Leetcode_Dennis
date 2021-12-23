class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        int fastIndex = 0;
        
        if (nums.size() == 0)
            return 0;
        
        for (fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
            if (nums[slowIndex] != nums[fastIndex]) {
                slowIndex++;
                nums[slowIndex] = nums[fastIndex];
            }
        }
        
        return slowIndex+1;
    }
};
