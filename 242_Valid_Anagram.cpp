class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; s[i] != '\0' ;i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                record[s[i] - 'a']++;
            }
        }
        
        for (int i = 0; t[i] != '\0'; i++) {
            if (t[i] >= 'a' && t[i] <= 'z') {
                record[t[i] - 'a']--;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0)
                return false;
        }
        
        return true;
    }
};
