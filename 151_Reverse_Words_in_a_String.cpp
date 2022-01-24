class Solution {
public:
    string reverseWords(string s) {
        vector<string> words; // 搜集切開來的所有word
        string ans = "";
        int i, j;
        int len = s.size();
        
        i = 0;
        while (i < len) {
            // 尋找word開始位置
            while (i < len && (s[i] == ' ' || s[i] == '\t')) i++;
            
            // 尋找word結束位置
            j = i;
            while ((j + 1) < len && (s[j + 1] != ' ' && s[j + 1] != '\t')) j++;
            
            /* 檢查開頭位置是不是已經到字串結尾
               到字串尾端時,那次就不是一個word
             */
            if (i < len) {
                string word = s.substr(i, j - i + 1);
                words.push_back(word);
                i = j + 1;   
            }
        }
        
        for (i = words.size() - 1; i > 0; i--) {
            ans += words[i] + " ";
        }
        
        ans += words[0];
        return ans;
    }
};
