#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
			return 0;
		vector<int> index_of_last_ch(128, -1);
		
		int longest = 0;
		int cur_len = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			int last_index = index_of_last_ch[s[i]];
			if (last_index == -1 || (i - last_index > cur_len))
			{
				++cur_len;
			}
			else if (i - last_index <= cur_len)
			{
				cur_len = i - last_index;
			}
			index_of_last_ch[s[i]] = i;
			
			longest = cur_len > longest ? cur_len : longest;
		}
		
		return longest;
    }
};