class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
            
        int count = 1;
        int prev = nums[0];
        vector<int> result;
        result.push_back(prev);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (prev != nums[i])
            {
                ++count;
                result.push_back(nums[i]);
            }
            prev = nums[i];
        }
        
        nums.swap(result);
        return count;
    }
};