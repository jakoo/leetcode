class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long result = numeric_limits<int>::max();
        long minDif = result - target;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            int iVal = nums[i];
            while (j < k)
            {
                long cur = iVal + nums[j] + nums[k];
                long dif = fabs(cur - target);
                if (dif < minDif)
                {
                    minDif = dif;
                    result = cur;
                }
                if (cur > target)
                {
                    --k;
                    while (k > j && nums[k] == nums[k + 1]) //skip same value
                        --k;
                }
                if (cur == target)
                    return cur;
                if (cur < target)
                {
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) //skip same value
                        ++j;
                }
            }
        }
        return result;
    }
};