/* perfect square : 1 = 1*1
                    4 = 2*2
                    9 = 3*3
                    16 = 4*4
                    25 = 5*5
                    36 = 6*6
                    ... ...
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        // [left, right] condition
        int left = 1;
        int right = num/2;
        int root = 1;
        
        if (num == 1)
            return true;
        
        while (left <= right) {
            root = left + ((right-left) >> 1);
            if (root > num/root) { // 不能直接root*root,有可能overflow
                right = root-1;
            } else if (root < num/root) { // 不能直接root*root,有可能overflow
                left = root+1;
            } else if (root*root == num) { // 這時候的root*root只會<=num
                return true;
            } else {
                break;
            }
        }
        
        return false;
    }
};
