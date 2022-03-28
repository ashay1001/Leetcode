class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1, mid; 
        
        while(low <= high)
        {
            mid = (low+high)/2;
            
            if(nums[mid] == target) return true;
            
            else if(nums[low] == nums[mid] and nums[mid] == nums[high]) //we dont know which sub array is sorted 
            {
                low++; high--;
            }
            
            else if(nums[low] <= nums[mid]) //if left sub-array is sorted
            {
                if(target <= nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else    //if not then right must be sorted
            {
                if(target >= nums[mid] and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};