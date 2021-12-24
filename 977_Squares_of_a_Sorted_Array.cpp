class Solution {
public:  
    vector<int> sortedSquares(vector<int>& nums) {
        // 利用雙指標,而不單純平方完再用sort排序
        int leftForwardIndex = 0;
        int rightForwardIndex = 0;
        int i = 0;
        vector<int> ans;
        
        // get the squares
        for (i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        
        /* find the start point i
           ... nums[i-2] > nums[i-1] > nums[i] > nums[i+1] ...
         */
        for (i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) {
                /* 不能寫在這裡,需要寫在外面
                   由最後找的i來確定leftForwardIndex
                   而且rightForwardIndex是leftForwardIndex的下一個 
                   
                 */
                //leftForwardIndex = i;
                //rightForwardIndex = leftForwardIndex + 1;
                break;
            }
        }
        
        leftForwardIndex = (i == nums.size()) ? nums.size()-1 : i;
        rightForwardIndex = leftForwardIndex + 1;
        
        while (leftForwardIndex >= 0 && rightForwardIndex < nums.size()) {
            if (nums[leftForwardIndex] < nums[rightForwardIndex]) {
                ans.push_back(nums[leftForwardIndex]);
                leftForwardIndex--;
            } else if (nums[leftForwardIndex] > nums[rightForwardIndex]) {
                ans.push_back(nums[rightForwardIndex]);
                rightForwardIndex++;
            } else {
                ans.push_back(nums[leftForwardIndex]);
                ans.push_back(nums[rightForwardIndex]);
                leftForwardIndex--;
                rightForwardIndex++;
            }
        }
        
        while (leftForwardIndex >= 0) {
            ans.push_back(nums[leftForwardIndex]);
            leftForwardIndex--;
        }
        
        while (rightForwardIndex < nums.size()) {
            ans.push_back(nums[rightForwardIndex]);
            rightForwardIndex++;
        }
        
        return ans;
    }
};
