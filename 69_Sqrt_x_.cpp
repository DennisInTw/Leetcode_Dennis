class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x/2;
        int root = 0;
        
        if (x <= 1)
            return x;
        
        while (left + 1 < right) {
            root = left + ((right-left) >> 1);
            if (root > x/root){
                right = root-1;
            } else if (root < x/root) {
                left = root;
            } else {
                return root;
            }
        }
        
        return (right<=x/right) ? right : left;
    }
};
