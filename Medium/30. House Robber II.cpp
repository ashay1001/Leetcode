class Solution {
public:
    int rob(vector<int>& nums) {
     
        if(nums.empty() || nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        return max(robber(nums, 0, nums.size()-2), robber(nums, 1, nums.size()-1));
    }
    
    int robber(vector<int> &nums, int start, int end)
    {
        int pre = 0, cur = 0;
        for (int i = start; i <= end; i++) 
        {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};