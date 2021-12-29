/*    target在nums裡面有三種情況 :
      Case1 : target不在nums範圍內, 例如 : target = 0 , nums = [1,2,2,3,3]  或 target = 6 , nums = [1,2,2,3,3]
      
      Case2 : target在nums範圍內,但是nums裡沒有target的數字
      
      Case3 : target在nums範圍內,且nums含有target
      
      
      利用兩個API來尋找左邊界和右邊界
      當nums和target是Case1情況時,
      如果target是在nums的左邊,則尋找右邊界時,最後right會小於0,而left=0
      如果target是在nums的右邊,則尋找左邊界時,最後right會超過nums.size(),而right=nums.size()-1
      所以需要加上判斷left>nums.size()以及right<0
      
      當nums和target是Case2和Case3情況時,
      找到最後right<left而停止搜尋時,判斷是不是等於target
 */

class Solution {
public:
    int findLeftBoundary(vector<int>& nums, int target) {
        /* [left, right]
           不斷向左尋找,所以一直扣除右邊的>=target元素
           左邊出現<target就向右前進
           所以最後left如果在0 ~ nums.szie()-1範圍內
           nums[left]只會是target或不是target
         */
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + ((right-left) >> 1);
            
            if (nums[mid] >= target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        if (left == nums.size() || nums[left] != target)
            return -1;
        else
            return left;
    }
    
    int findRightBoundary(vector<int>& nums, int target) {
        /* [left, right]
           不斷向右尋找,所以一直扣除左邊的<=target元素
           右邊出現>target就向左前進
           所以最後right如果在0 ~ nums.szie()-1範圍內
           nums[right]只會是target或不是target
         */
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + ((right-left) >> 1);
            
            if (nums[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        if (right < 0 || nums[right] != target)
            return -1;
        else
            return right;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // 二分搜
        int leftBoundary = 0;
        int rightBoundary = 0;
        
        leftBoundary = findLeftBoundary(nums, target);
        rightBoundary = findRightBoundary(nums, target);
        
        return {leftBoundary, rightBoundary};
    }
};
