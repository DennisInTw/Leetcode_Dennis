class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len = tokens.size();
        
        for (int i = 0; i < len; i++) {
            // 計算過程需要將結果再push到stack
            if (tokens[i] == "+") {
                int val1, val2;
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 + val1);
            } else if (tokens[i] == "-") {
                int val1, val2;
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 - val1);
            } else if (tokens[i] == "*") {
                int val1, val2;
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 * val1);
            } else if (tokens[i] == "/") {
                int val1, val2;
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 / val1);
            } else {
                int val = stoi(tokens[i]);
                st.push(val);
            }
        }
        
        // stack裡只剩一個元素, 就是最後計算結果
        return st.top();
    }
};
