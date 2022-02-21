class Solution {
public:
    // 用列方式來計算
    int trap(vector<int>& height) {
        // 用雙指標方式來找左右兩邊的最大高度
        // Time Complexity : O(n^2)
        int maxLeft, maxRight;
        int len = height.size();
        int count = 0; // 計算全部可以累積多少雨水
        int h = 0; // 計算當下bar可以累積雨水的高度
        
        // 依序向每一個bar來計算累積雨量
        for (int i = 0; i < len; i++) {
            // 左右兩邊不能累積雨水
            if (i == 0 || i == len - 1) continue;
            
            maxLeft = height[i];
            // 向左找最大高度
            for (int j = i - 1; j >= 0; j--) {
                if (maxLeft < height[j]) {
                    maxLeft = height[j];
                }
            }
            
            maxRight = height[i];
            // 向右找最大高度
            for (int j = i + 1; j < len; j++) {
                if (maxRight < height[j]) {
                    maxRight = height[j];
                }
            }
            
            // area = h * 1 (寬度為1)
            h = min(maxLeft, maxRight) - height[i];
            
            // 注意 : 算出來的h可能為負的, 表示該bar不能累積雨水
            if (h > 0) {
                count += h;
            }
        }
        
        return count;
    }
};
