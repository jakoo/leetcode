class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> pvec;
        pvec.push_back(make_pair(1000, "M"));
        pvec.push_back(make_pair(900, "CM"));
        pvec.push_back(make_pair(500, "D"));
        pvec.push_back(make_pair(400, "CD"));
        pvec.push_back(make_pair(100, "C"));
        pvec.push_back(make_pair(90, "XC"));
        pvec.push_back(make_pair(50, "L"));
        pvec.push_back(make_pair(40, "XL"));
        pvec.push_back(make_pair(10, "X"));
        pvec.push_back(make_pair(9, "IX"));
        pvec.push_back(make_pair(5, "V"));
        pvec.push_back(make_pair(4, "IV"));
        pvec.push_back(make_pair(1, "I"));
        
        string s;
        for (int i = 0; num > 0; ++i)
        {
            int x = num / pvec[i].first;
            if (x > 0)
            {
                for (int j = 0; j < x; ++j)
                    s.append(pvec[i].second);
                num %= pvec[i].first;
            }
            
        }
        return s;
        
    }
};