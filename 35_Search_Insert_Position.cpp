/*   Test Case : 
                [1,3,5,7]
                6
                [1,2,3,4]
                5
                [1,2,3,4]
                0
                [1,2,3,10]
                6
                
     
     Only need to notice the "not found" case, we can find :
     
     If target need to be inserted at nums[middle]'s right side,
     then left == right and left > middle
     
     If target need to be inserted at nums[middle]'s left side,
     then left == right and left == middle.
     Original nums[left] need to move left
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
        
        /* if need to insert to the right side of nums[middle], return middle+1;
           Or, return middle;
        */
        return (middle < left) ? (middle + 1) : middle;
    }
};
