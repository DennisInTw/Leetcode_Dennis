class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map solution
        unordered_map<int, int> map;
        int len = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < len; i++) {
            if (map.count(target - nums[i]) == 1) {
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
