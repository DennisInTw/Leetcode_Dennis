class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> calcVal;
        int sum;
        
        while (n != 1 && calcVal.count(n) == 0) {
            calcVal.insert(n);
            sum = 0;
            
            while (n > 0) {
                int digit = n%10;
                sum += (digit * digit);
                n /= 10;
            }
            
            n = sum;
        }
        
        if (n == 1)
            return true;
        else
            return false;
    }
};
