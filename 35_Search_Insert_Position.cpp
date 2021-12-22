/*   Test Case : 
                [1,3,5,7]
                6
                [1,2,3,4]
                5
                [1,2,3,4]
                0
                [1,2,3,10]
                6
      For [left, right) condition          
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle = 0;
        
        while (left < right) {
            middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        
        return left;
    }
};
