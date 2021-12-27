class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // [left, right) solution
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m*n, 0);
        int startx = 0, starty = 0;
        int i = 0, j = 0, k = 0;
        int offset = 1;
        int limit = 0;
        
        if (m == n && m%2 != 0) {
            limit = m*n -1;
            ans[n*n-1] = matrix[n/2][n/2];
        } else {
            limit = m*n;
        }
        
        while (k < limit) {
            for (j = starty; j < starty+(n-offset); j++) {
                ans[k++] = matrix[startx][j];
                if (k == limit)
                    return ans;
            }
            
            for (i = startx; i < startx+(m-offset); i++) {
                ans[k++] = matrix[i][j];
                if (k == limit)
                    return ans;
            }
            
            for (; j > starty; j--) {
                ans[k++] = matrix[i][j];
                if (k == limit)
                    return ans;
            }
            
            for (; i > startx; i--) {
                ans[k++] = matrix[i][j];
                if (k == limit)
                    return ans;
            }
            
            startx++;
            starty++;
            offset += 2;
        }
        
        return ans;
        
    }
};
