class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        coreKSum(nums, target, 4, vector<int>(), 0, result);
        return result;
    }
    
    void coreKSum(vector<int>& nums, int target, int k, vector<int> numArray, int begin, vector<vector<int>>& result)
    {
        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[begin + i];
        }
        if (sum > target)
            return;
            
        if (k == 2)
        {
            int end = nums.size() - 1;
            sum = 0;
            while (begin < end)
            {
                sum = nums[begin] + nums[end];
                if (sum == target)
                {
                    vector<int> tmp(numArray);
                    tmp.push_back(nums[begin]);
                    tmp.push_back(nums[end]);
                    result.push_back(tmp);
                    ++begin;
                    while (begin < end && nums[begin] == nums[begin - 1]) ++begin;
                }
                else if (sum > target)
                {
                    --end;
                    while (begin < end && nums[end] == nums[end + 1]) --end;
                }
                else // sum < target
                {
                    ++begin;
                    while (begin < end && nums[begin] == nums[begin - 1]) ++begin;
                }
            }
            return;
        }
        
        // k > 2
        numArray.push_back(0);
        for(int i = begin; i <= nums.size() - k;)
        {
            sum = nums[i];
            for (int j = 1; j < k; ++j)
            {
                sum += nums[nums.size() - j];
            }
            if (sum < target)
            {
                ++i;
                while (i <= nums.size() - k && nums[i] == nums[i - 1]) ++i;
                continue;
            }
            numArray.pop_back();
            numArray.push_back(nums[i]);
            coreKSum(nums, target - nums[i], k - 1, numArray, i + 1, result);
            ++i;
            while (i <= nums.size() - k && nums[i] == nums[i - 1]) ++i;
        }
    }
};