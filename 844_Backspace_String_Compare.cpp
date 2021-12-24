class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /* 雙指標法
           slowIndex : 指當下可以存放字元的位置
           fastIndex : 指當下的字串位置
         */
        int slowIndex_s = 0, slowIndex_t = 0;
        int fastIndex_s = 0, fastIndex_t = 0;
        int len_s = s.length();
        int len_t = t.length();
        string clear_s, clear_t;
        
        // process string s
        for (fastIndex_s = 0; fastIndex_s < len_s; fastIndex_s++) {
            if (s[fastIndex_s] != '#') {
                s[slowIndex_s++] = s[fastIndex_s];
            } else if (slowIndex_s > 0) {
                slowIndex_s--;
            }
        }
        
        // process string t
        for (fastIndex_t = 0; fastIndex_t < len_t; fastIndex_t++) {
            if (t[fastIndex_t] != '#') {
                t[slowIndex_t++] = t[fastIndex_t];
            } else if (slowIndex_t > 0) {
                slowIndex_t--;
            }
        }
        
        clear_s = s.substr(0, slowIndex_s);
        clear_t = t.substr(0, slowIndex_t);
        
        if (clear_s == clear_t)
            return true;
        else
            return false;
    }
};
