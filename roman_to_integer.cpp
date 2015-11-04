class Solution {
public:
    int romanToInt(string s) {
        map<char, int> pmap;
        pmap['M'] = 1000;
        pmap['D'] = 500;
        pmap['C'] = 100;
        pmap['L'] = 50;
        pmap['X'] = 10;
        pmap['V'] = 5;
        pmap['I'] = 1;
        
        int sum = 0;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            auto next = it + 1;
            if (pmap[*it] < pmap[*next])
            {
                sum += pmap[*next] - pmap[*it];
                ++it;
            }
            else
            {
                sum += pmap[*it];
            }
        }
        return sum;
    }
};