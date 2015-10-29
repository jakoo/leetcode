class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0)
        {
            if (x == INT_MIN)
                return 0;
            negative = true;
            x = -x;
        }
        
        long result = 0;
        while (x > 0)
        {
            int num = x % 10;
            x /= 10;
            result = result * 10 + num;
        }
        
        if (result > INT_MAX)
            return 0;
        
        if (negative)
            return -result;
        return result;
    }
};