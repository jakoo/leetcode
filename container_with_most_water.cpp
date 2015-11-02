class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0;
        while (left < right)
        {
            int water = min(height[left], height[right]) * (right - left);
            if (water > max)
                max = water;
            if (height[left] > height[right])
                --right;
            else
                ++left;
        }
        return max;
    }
};