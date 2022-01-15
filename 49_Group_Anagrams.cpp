class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strmap;
        vector<vector<string>> ans;
        
        for (auto& str : strs) {
            auto keyStr = str;
            sort(keyStr.begin(), keyStr.end());
            strmap[keyStr].push_back(str);
        }
        
        for (auto& [key, strVec] : strmap) {
            ans.push_back(strVec);
        }
        
        return ans;
    }
};
