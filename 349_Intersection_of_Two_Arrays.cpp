class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersectValues;
        vector<int> ans;
        
        for (auto& val : nums1) {
            intersectValues.insert(val);
        }
        
        for (auto& val : nums2) {
            if (intersectValues.count(val) == 1) {
                ans.push_back(val);
                intersectValues.erase(val);
            }
        }
        
        return ans;
    }
};
