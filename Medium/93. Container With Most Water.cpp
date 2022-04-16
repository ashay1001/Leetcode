class Solution {
public:
    int maxArea(vector<int>& height) {
     
        int len = height.size();
        int left = 0;
        int right = len - 1;
        int maxarea = min(height[left], height[right]) * (right - left);
        
        while (left < right) 
        {
            // Move the shorter lines each time
            if (height[left] <= height[right])
                left++;
            else
                right--;

            // update the max area
            maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
        }

        return maxarea;

    }
};