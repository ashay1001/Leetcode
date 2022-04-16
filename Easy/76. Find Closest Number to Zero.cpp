class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int _min = abs(nums[0]), original = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(abs(nums[i]) < _min)
            {
                _min = abs(nums[i]);
                original = nums[i];
            }
            else if(abs(nums[i]) == _min)
                original = max(original, nums[i]);
        }
        return original;
    }
};