class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int val1, val2;
        int a = 0;
        int b = temp.size() - 1;
        while (a < b)
        {
            int sum = temp[a] + temp[b];
            if ( sum > target)
                --b;
            else if ( sum < target )
                ++a;
            else
            {
                val1 = temp[a];
                val2 = temp[b];
                break;
            }
        }

        bool find_first = false;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val1 || nums[i] == val2)
            {
                if (!find_first)
                {
                    a = i;
                    find_first = true;
                }
                else
                {
                    b = i;
                    break;
                }
            }
        }
        temp.clear();
        temp.push_back(a + 1);
        temp.push_back(b + 1);
        return temp;
    }
};
