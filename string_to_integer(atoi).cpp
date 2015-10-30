class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0)
            return 0;
            
        auto it = str.begin();
        //clear '0' or ' ' in front
        while (it != str.end() && (*it == 0 || *it == ' ')) ++it;
        
        bool negative = false;
        if (*it == '-')
        {
            negative = true;
            ++it;
            if (!is_num(*it))
                return 0;
        }
        if (*it == '+')
        {
            ++it;
            if (!is_num(*it))
                return 0;
        }
        
        //clear '0' behind '-' in front of nums 
        while (it != str.end() && *it == 0) ++it;
        
        long result = 0;
        long int_max = numeric_limits<int>::max();
        long int_min = numeric_limits<int>::min();
        for(; it != str.end() && is_num(*it); ++it)
        {
            int num = *it - '0';
            result = 10 * result + num;
            if (result > int_max)
                break;
        }
        
        if (negative)
        {
            result = -result;
            if (result < int_min)
                return int_min;
            return result;
        }
        // positive
        if (result > int_max)
            return int_max;
        return result;
    }
    
    bool is_num(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
};