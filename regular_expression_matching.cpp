#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    typedef string::iterator StrIt;
    bool isMatch(string s, string p) {
        vector<vector<int>> buffer(s.size() + 1, vector<int> (p.size() + 1, -1));
        return isMatchCore(s, 0, s.size(), p, 0, p.size(), buffer);   
    }
    
    bool isMatchCore(string& s, int si, int send, string& p, int pi, int pend,
                    vector<vector<int>>& buffer)
    {
        if (buffer[si][pi] == 0)
            return false;
        if (si == send && pi == pend)
            return true;
        if (si != send && pi == pend)
        {
            buffer[si][pi] = 0;
            return false;
        }
        if (si == send && pi != pend)
            if (pend - pi >= 2 && p[pi + 1] == '*')
                return isMatchCore(s, si, send, p, pi + 2, pend, buffer);
            else
            {
                buffer[si][pi] = 0;
                return false;
            }
        if (s[si] != p[pi] && p[pi] != '.')
            if (pend - pi >= 2 && p[pi + 1] == '*')
                return isMatchCore(s, si, send, p, pi + 2, pend, buffer);
            else
            {
                buffer[si][pi] = 0;
                return false;
            }
            
        // (s[si] == p[pi]) || (p[pi] == '.')
        if (pend - pi >= 2 && p[pi + 1] == '*')
        {
            if (isMatchCore(s, si + 1, send, p, pi, pend, buffer) ||
                isMatchCore(s, si, send, p, pi + 2, pend, buffer) ||
                isMatchCore(s, si + 1, send, p, pi + 2, pend, buffer))
                return true;

                
            buffer[si][pi] = 0;
            return false;
        }

        return isMatchCore(s, si + 1, send, p, pi + 1, pend, buffer);
    }
};

int main()
{
	//string s("aaaaaaaaaaaaab");
	//string p("a*a*a*a*a*a*a*a*a*a*c");
	string s("ab");
    string p(".*c");
    Solution solution;
	if (solution.isMatch(s, p))
        cout << "True" << endl;
    else
        cout << "False" << endl;
	return 0;
}