class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(sum % 2 == 1) return false;
        return solve(nums, sum/2, n);
    }
    
    bool solve(vector<int> &nums, int sum, int n)
    {
        if(sum == 0) return true;
        if(n==0 || sum<0) return false;
        
        if(nums[n-1] <= sum)
        {
            bool include = solve(nums, sum-nums[n-1], n-1);
            bool exclude = solve(nums, sum, n-1);
            return include || exclude;
        }
        else
            return solve(nums, sum, n-1);
    }
};