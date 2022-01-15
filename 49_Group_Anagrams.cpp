class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int strsLen = strs.size();
        int** record = new int*[strsLen];
        int* inList = new int[strsLen];
         vector<vector<string>> ans;
        int index = 0, match = 0;
        
        for (int i = 0; i < strsLen; i++) {
            record[i] = new int[26];
            memset(record[i], 0x0, 26 * sizeof(int));
        }
        
        for (int i = 0; i < strsLen; i++) {
            for (int j = 0; strs[i][j] != '\0'; j++) {
                record[i][strs[i][j] - 'a']++;
            }
        }
        
        memset(inList, 0x0, strsLen * sizeof(int));
        
        for (int i = 0; i < strsLen; i++) {
            if (inList[i] == 0) {
                inList[i] = 1;
                vector<string> tmp;
                tmp.push_back(strs[i]);

           
                for (int j = i + 1; j < strsLen; j++) {
                    if (inList[j] == 0) {
                        match = 1;
                        for (int k = 0; k < 26; k++) {
                            if (record[i][k] != record[j][k]) {
                                match = 0;
                                break;
                            }
                        }
                    
                        if (match) {
                            tmp.push_back(strs[j]);
                            inList[j] = 1;
                        }
                    }                   
                }
                ans.push_back(tmp);
                index++;
            }
        }
        
        return ans;
    }
};
