class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int mid = search(nums, target);
        if(mid == -1) return {-1, -1};
        
        int left = mid, right = mid;
        for(int i = mid-1; i>=0; i--)
            if(nums[i] == nums[mid])
                left = i;
        for(int i = mid+1; i<nums.size(); i++)
            if(nums[i] == nums[mid])
                right = i;
        
        return {left, right};
    }
    
    int search(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) return mid;
            if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};