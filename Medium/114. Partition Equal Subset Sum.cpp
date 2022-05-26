class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        
        return solve(nums, sum/2);
    }
    
    bool solve(vector<int> &nums, int sum)
    {
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1));
        
        for(int i=0; i<sum+1; i++)
            dp[0][i] = false;
        for(int i=0; i<nums.size()+1; i++)
            dp[i][0] = true;
        
        for(int i=1; i<=nums.size(); i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        for(int i=0; i<=nums.size(); i++)
        {
            for(int j=0; j<=sum; j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        return dp[nums.size()][sum];
    }
};