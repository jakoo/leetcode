#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

    	if (nums.size() < 3)
    		return result;

        sort(nums.begin(), nums.end());
        int bound = 0;
        while (nums[bound] < 0)
        	++bound;
        for (int i = 0; i < bound;)
        {
	        threeSumCore(nums, i, nums.size() - 1, bound, result);
	        ++i;
	        while (i < bound && nums[i] == nums[i - 1]) ++i;
        }
        if (nums[bound] == 0)
        	threeSumCore(nums, bound, nums.size() - 1, bound, result);
        return result;
    }

    void threeSumCore(vector<int>& nums, int min, int max, int bound, vector<vector<int>>& result)
    {
    	if (nums[min] == 0) 
    	{
    		if(min + 2 <= max && nums[min + 1] == 0 && nums[min + 2] == 0)
	    	{
	    		vector<int> temp(3, 0);
	    		result.push_back(temp);
	    	}
	    	return;
	    }

    	if (max < bound)
    		return;

    	int minVal = nums[min];
    	int maxVal = nums[max];

		int index = minVal + maxVal <= 0 ? bound : min + 1;
		while (true)
		{
			if (minVal + maxVal <= 0 && index >= max)
				break;

			if (minVal + maxVal + nums[index] < 0)
			{
				++index;
				while (nums[index] == nums[index - 1]) //skip same value
					++index;
			}
			else if (minVal + maxVal + nums[index] == 0)
			{
				vector<int> temp;
				temp.push_back(minVal);
				temp.push_back(nums[index]);
				temp.push_back(maxVal);
				result.push_back(temp);
				break;
			}
			else // minVal + maxVal + nums[index] > 0
				break;
		}

		
		int newMax = max - 1;
		if (nums[newMax] == maxVal)
			while (nums[newMax] == nums[newMax + 1]) 
			{
				--newMax;
				if (newMax < bound)
					return;
			}
			
		threeSumCore(nums, min, newMax, bound ,result);
		return;
    }
};

int main()
{
	Solution solution;
	vector<int> v {-1, -1, 0, 1, 1,2,-2, 0, 0, 0};
	solution.threeSum(v);
	return 0;
}