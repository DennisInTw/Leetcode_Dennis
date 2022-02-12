class Solution {
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
    
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int* next = new int[len];
        
        getNext(next, s);
        
        /* 扣除suffix部分
           如果能夠整除字串長度,表示有重複substring可以組成完整string
           (next[len - 1] != 0)必須滿足,因為只有在prefix和suffix相同時才有機會
        */
        if (next[len - 1] != 0 && 
            (len % (len - next[len - 1])) == 0) {
            delete []next;
            return true;
        } else {
            delete []next;
            return false;
        }
        
        
    }
};459. Repeated Substring Pattern
