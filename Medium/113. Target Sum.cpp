class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
     
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s1 = (sum + target)/2;
        
        if(nums.size() == 1) return abs(nums[0]) == abs(target);
        if(target > sum) return 0;
        if((sum+target)%2 == 1) return 0;
        
        return subsetSumCount(nums, s1);
    }
    
    int subsetSumCount(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};