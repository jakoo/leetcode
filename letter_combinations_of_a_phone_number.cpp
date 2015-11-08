class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<char, vector<char>> dmap;
        dmap['2'] = {'a', 'b', 'c'};
        dmap['3'] = {'d', 'e', 'f'};
        dmap['4'] = {'g', 'h', 'i'};
        dmap['5'] = {'j', 'k', 'l'};
        dmap['6'] = {'m', 'n', 'o'};
        dmap['7'] = {'p', 'q', 'r', 's'};
        dmap['8'] = {'t', 'u', 'v'};
        dmap['9'] = {'w', 'x', 'y', 'z'};
        
        core(digits, 0, dmap, result, string());
        return result;
    }
    
    void core(string& digits, int index, 
              unordered_map<char, vector<char>>& dmap, 
              vector<string>& result, string str)
    {
        typedef vector<char>::iterator vcit;
        
        char ch = digits[index];
        
        if (ch < '2' && ch > '9')
        {
            result.clear();
            return;
        }
        
        if (index == digits.size() - 1)
        {
            for (vcit it = dmap[ch].begin(); it != dmap[ch].end(); ++it)
            {
                result.push_back(string(str + *it));
            }
            return;
        }
        
        for (vcit it = dmap[ch].begin(); it != dmap[ch].end(); ++it)
        {
            core(digits, index + 1, dmap, result, str + *it);
        }
    }
};