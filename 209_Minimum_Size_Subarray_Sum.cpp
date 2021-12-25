class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Brute force solution
        int sum = 0;
        int minLen = nums.size()+1;
        int len = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                
                if (sum >= target) {
                    len = (j - i + 1);
                    minLen = (len < minLen) ? len : minLen;
                }
            }
        }
        
        return (minLen < nums.size()+1) ? minLen : 0;
    }
};
