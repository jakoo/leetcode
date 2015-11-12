class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        core(n, n, n, string(), result);
        return result;
    }
    
    void core(int n, int left, int right, string str, vector<string>& result)
    {
        if (left == 0)
        {
            str.append(right, ')');
            result.push_back(str);
            return;
        }
        
        if (left == n)
        {
            core(n, left - 1, right, str + '(', result);
            return;
        }
        
        if (right >= left)
        {
            core(n, left - 1, right, str + '(', result);
        }
        
        if (n - right < n - left)
        {
            core(n, left, right - 1, str + ')', result);    
        }
    }
};