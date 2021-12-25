class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Sliding window solution
        int basketFruit1 = -1, basketFruit2 = -1;
        int windowStart = 0, windowEnd = 0;
        int maxFruit = 0;
        int numberFruit = 0;
        int t = 0;
        
        basketFruit1 = fruits[0];
        numberFruit = 1;
        windowEnd = 1;
        
        while (windowEnd < fruits.size() && fruits[windowEnd] == basketFruit1) {
            windowEnd++;
            numberFruit++;
        }
        
        if (windowEnd == fruits.size()) {
            return numberFruit;
        }
        
        basketFruit2 = fruits[windowEnd];
        numberFruit++;
        windowEnd++;
        
        for (; windowEnd < fruits.size(); windowEnd++) {
            if (fruits[windowEnd] == basketFruit1 ||
                     fruits[windowEnd] == basketFruit2) {
                numberFruit++; // pick up one fruit
            } else {
                maxFruit = (numberFruit > maxFruit) ? numberFruit : maxFruit;
                
                t = windowEnd -1;
                while (fruits[t] == fruits[windowEnd-1]) {
                    t--;
                }
                
                windowStart = t + 1;
                numberFruit = windowEnd - windowStart + 1;
                if (basketFruit1 == fruits[windowEnd-1]) {
                    basketFruit2 = fruits[windowEnd];
                } else {
                    basketFruit1 = fruits[windowEnd];
                }   
            }   
        }
        
        
        return (maxFruit > numberFruit) ? maxFruit : numberFruit;
        
    }
};
