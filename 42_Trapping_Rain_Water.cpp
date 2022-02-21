class Solution {
public:
    // 用列方式來計算
    int trap(vector<int>& height) {
        // 用動態規劃方式來找左右兩邊的最大高度
        // Time Complexity : O(n),   Space Complexity : O(n)
        int* maxLeft, *maxRight;
        int len = height.size();
        int count = 0; // 計算全部可以累積多少雨水
        int h = 0; // 計算當下bar可以累積雨水的高度
        
        maxLeft = new int[len];
        maxRight = new int[len];
        
        // 左邊找最大高度的table
        maxLeft[0] = height[0];
        for (int i = 1; i < len; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        
        // 右邊找最大高度的table
        maxRight[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        
        // 依序向每一個bar來計算累積雨量
        for (int i = 0; i < len; i++) {
            // 左右兩邊不能累積雨水
            if (i == 0 || i == len - 1) continue;
            
            // area = h * 1 (寬度為1)
            h = min(maxLeft[i], maxRight[i]) - height[i];
            
            // 注意 : 算出來的h可能為負的, 表示該bar不能累積雨水
            if (h > 0) {
                count += h;
            }
        }
        
        delete []maxLeft;
        delete []maxRight;
        
        return count;
    }
};
