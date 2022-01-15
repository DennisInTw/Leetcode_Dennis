class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> intersectValues;
        vector<int> ans;
        
        for (auto& val : nums1) {
            intersectValues[val]++;
        }
        
        for (auto& val : nums2) {
            if (intersectValues[val] > 0) {
                ans.push_back(val);
                intersectValues[val]--;
            }
        }
        
        return ans;
    }
};
