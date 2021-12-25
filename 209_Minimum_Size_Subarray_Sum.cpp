class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding window solution
        int sum = 0;
        int minLen = INT32_MAX;
        int len = 0;
        int windowStart = 0, windowEnd = 0;
        
        for (windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            sum += nums[windowEnd];
            
            if (sum >= target) {
                while (sum >= target) {
                    len = (windowEnd - windowStart + 1);
                    minLen = (len < minLen) ? len : minLen;
                    sum -= nums[windowStart];
                    windowStart++;
                }
            }
        }
        
        return (minLen != INT32_MAX) ? minLen : 0;   
    }
};
