#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

    string longestPalindrome(string s) {
        if (s.size() == 0)
            return string();
        char *format_str = new char[2003]();
        int *p = new int[2003]();
        p[0] = 1;
        format_str[0] = '$';
        format_str[1] = '#';
        string::iterator it = s.begin();
        int i = 2;
        for(; it != s.end(); ++it, ++i)
        {
            format_str[i] = *it;
            format_str[++i] = '#';
        }
        format_str[i] = '\0';

        int bi = 0; //border_index
        int li = 0; //longest_index
        for(int i = 1; format_str[i] != '\0'; ++i)
        {
            p[i] = bi > i ? min(p[2*li - i], bi - i) : 1;
            while(format_str[i + p[i]] == format_str[i - p[i]])
                ++p[i];
            if (p[i] >  p[li])
            {
                 bi = i + p[i] - 1;
                 li = i;
            }
        }
        int head = li - p[li] + 2;

        return string(s, head / 2 - 1, p[li] - 1);
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    string s("aba");
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}
