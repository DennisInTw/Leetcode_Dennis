class Solution {
    // KMP implement
public:
    // 算出prefix table,然後當作next table
    void getNext(int* next, const string pattern) {
        int patLen = pattern.size();
        int i, j;
        
        j = 0;
        next[0] = j;
        
        for (i = 1; i < patLen; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j-1];
            }
            
            if (pattern[i] == pattern[j]) {
                j++;
            }
            
            next[i] = j;
        }
    }
    
    // haystack : 原文字串
    // needle   : pattern
    int strStr(string haystack, string needle) {
        int textLen = haystack.size();
        int patLen = needle.size();
        int* next = NULL;
        int i, j;
        
        if (patLen == 0) {
            return 0;
        }
        
        next = new int[patLen];
        getNext(next, needle);
        j = 0;
        
        for (i = 0; i < textLen; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            
            if (haystack[i] == needle[j]) {
                j++;
            }
            
            if (j == patLen) {
                return (i - patLen + 1);
            }
        }
        
        return -1;
    }
};
