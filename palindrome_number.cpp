class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
            
        int k = getNumDigit(x);
        
        for (int i = 1, j = k; i < j; ++i, --j)
        {
            if (getKthNum(x, i) != getKthNum(x, j))
                return false;
        }
        
        return true;
    }
    int getNumDigit(int x)
    {
        int k = 1;
        while (x /= 10) ++k;
        return k;
    }
    int getKthNum(int x, int k)
    {
        if (k == 1)
            return x % 10;

        long mask = pow(10, k);
        return (x % mask - x % (mask / 10)) / (mask / 10);
    }
};