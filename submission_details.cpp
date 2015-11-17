class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;
        for(int n : nums)
        {
            if (n != val)
                result.push_back(n);
        }
        result.swap(nums);
        return nums.size();
    }
};