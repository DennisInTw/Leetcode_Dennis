class Solution {
public:
    /* 思考哪些為invalid :
           1. 左括號有多餘 : 括號匹配結束, 但是stack裡面不為空
           2. 括號沒有多餘 : 括號匹配過程中, 出現匹配不正確
           3. 右括號有多餘 : 括號匹配過程中, stack已經為empty, 沒有匹配的左括號
    
        stack放進右括號, 而不是左括號
        這樣可以省掉很多if判斷不同括號, 直接判斷當下右括號和stack的top是不是相同
    */
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            // 放進右括號到stack, 而不是左括號
            if (s[i] == '(') {
                st.push(')');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '{') {
                st.push('}');
            } else if (st.empty() || st.top() != s[i]) {
                // Case3 and Case2
                return false;
            } else {
                st.pop();
            }
        }
        
        // Case2
        return st.empty();
    }
};
