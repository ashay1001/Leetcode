class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int N = nums.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return matrixChainMultiplication(nums, 1, N-1, dp);
    }
    
    int matrixChainMultiplication(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int maximum = INT_MIN;
        
        for(int k=i; k <= j-1; k++)
        {
            int temp = matrixChainMultiplication(arr, i, k, dp) + matrixChainMultiplication(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
            
            if(temp > maximum)
                maximum = temp;
        }
        dp[i][j] = maximum;
        return dp[i][j];
    }
};