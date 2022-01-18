class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Brute force : time complexity = O(n^4)
        // Hash : time complexity = O(n^2 + n^2)
        
        unordered_map<int,int> map_sum1_2;
        unordered_map<int,int> map_sum3_4;
        int len = nums1.size();
        int ans = 0;
        
        // O(n^2)
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int sum = nums1[i] + nums2[j];
                map_sum1_2[sum]++;
            }
        }
        
        // O(n^2)
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int sum = nums3[i] + nums4[j];
                //if (map_sum1_2.count(0 - sum) == 1) {
                if (map_sum1_2.find(0 - sum) != map_sum1_2.end()) {
                    ans += (map_sum1_2[0 - sum]);
                }
            }
        }
        
        return ans;
    }
};
