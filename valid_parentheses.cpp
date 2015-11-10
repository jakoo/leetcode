class Solution {
public:
    bool isValid(string s) {
        stack<char> chs;
        for (char ch : s)
        {
            if (ch == '(')
                chs.push(')');
            if (ch == '{')
                chs.push('}');
            if (ch == '[')
                chs.push(']');
            if (ch == ')' || ch == '}' || ch == ']')
                if (chs.empty() || chs.top() != ch)
                    return false;
                else
                {
                    chs.pop();
                }
        }
        if (chs.empty())
            return true;
        return false;
    }
};