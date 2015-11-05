class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return string();
        if (strs.size() == 1)
            return strs[0];
        int minLen = longestCommonPrefix(strs[0], strs[1], -1);
        for (auto vit = strs.begin() + 1, nextit = strs.begin() + 2;
            nextit != strs.end(); ++vit, ++nextit)
        {
            int len = longestCommonPrefix(*vit, *nextit, minLen);
            if (len < minLen)
                minLen = len;
        }
            
        
        return string(strs[0], 0, minLen);
    }
    
    int longestCommonPrefix(string& str1, string& str2, int len)
    {
        int result = 0;
        auto sit1 = str1.begin(), sit2 = str2.begin();
        for(int i = 0;
            sit1 != str1.end() && sit2 != str2.end() && 
            *sit1 == *sit2 && (i < len || len == -1); 
            ++sit1, ++sit2)
        {
            ++result;
        }
        return result;
    }
};