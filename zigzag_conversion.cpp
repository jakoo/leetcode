#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = (numRows - 1) * 2;
        if (numRows == 1)
			return s;
			
        vector<int> first_steps;
        first_steps.push_back(len);
        int first_len = len - 2;
        for(int i = 0; i < numRows - 2; ++i)
        {
            first_steps.push_back(first_len);
            first_len -= 2;
        }
        first_steps.push_back(len);
        
        string result;
        for(int i = 0; i < numRows; ++i)
        {
            int index = i;
			vector<int> step;
            if (i == 0 || i == numRows - 1)
			{
				step.push_back(len);
				step.push_back(len);
			}
			else
			{
				step.push_back(first_steps[i]);
				step.push_back(len - first_steps[i]);
			}

            int flag = 0;
            while (index < s.size())
            {
                result.push_back(s[index]);
                index += step[flag];
                flag = 1 - flag;
            }
        }
        return result;
    }
};

int main(void)
{
	Solution solution;
	string s("ABCDEFG");
	solution.convert(s, 4);
	return 0;
}