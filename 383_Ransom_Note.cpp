class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; magazine[i] != '\0'; i++) {
            record[magazine[i] - 'a']++;
        }
        
        for (int i = 0; ransomNote[i] != '\0'; i++) {
            if (record[ransomNote[i] - 'a'] <= 0) {
                return false;
            } else {
                record[ransomNote[i] - 'a']--;
            }
        }
        
        return true;
    }
};
