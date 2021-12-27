class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int i = 0, j =0;
        int loop = n/2;
        int offset = 1;
        int count = 1;
        
        while (loop > 0) {
            --loop;
            
            for (j = starty; j < starty+(n-offset); j++) {
                ans[startx][j] = count++;
            }
            
            for (i = startx; i < startx+(n-offset); i++) {
                ans[i][j] = count++;
            }
            
            for (; j > starty; j--) {
                ans[i][j] = count++;
            }
            
            for (; i > startx; i--) {
                ans[i][j] = count++;
            }
            
            startx++;
            starty++;
            offset += 2;
        }
        
        if (n%2 != 0) {
            ans[n/2][n/2] = count;
        }
        
        return ans;
    }
};
