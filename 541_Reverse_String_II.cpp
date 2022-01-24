class Solution {
public:
    // 利用這個function來單獨做子字串的reverse
    // [start, end]
    void partitionReverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        /*  題目是說 : 在字串s裡依照底下規則來做reverse
            1. 每2k長度為一個單位,然後在這個單位裡面的前k個子字串做reverse
            2. 如果 k <= 子字串長度 < 2k, 則將前面k個子字串做reverse,剩下保留不動
            3. 如果 子字串長度 < k, 則將該子字串做reverse
         */
        int left, right;
        int len = s.size();
        
        // 規則1 : left為子字串開始, right為子字串結束
        // [left, right]
        left = 0;
        right = 2*k - 1;
        while (right < len) {
            partitionReverse(s, left, left + k - 1);
            left += 2*k;
            right += 2*k;
        }
        
        // 規則2
        if (len - left >= k) {
            partitionReverse(s, left, left + k - 1);
        } else { // 規則3
            partitionReverse(s, left, len - 1);
        }
        return s;
    }
};
