class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0; i<amount+1; i++)
            dp[0][i] = INT_MAX-1;
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = 0;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=0;j<amount+1; j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount]>=INT_MAX-1 ? -1:dp[n][amount];
    }
};
/*
Recursive:

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = unbdKnapSack(coins, amount, coins.size(), dp);
        if(ans >= INT_MAX-1) return -1;
        else return ans;
        
    }
    
    int unbdKnapSack(vector<int>& coins, int amount, int n, vector<vector<int>> &dp)
    {
        if(n==0 || amount==0) return (amount==0)?0:INT_MAX-1;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        
        if(coins[n-1] <= amount)
        {
            int a = 1 + unbdKnapSack(coins, amount-coins[n-1], n, dp);
            int b = unbdKnapSack(coins, amount, n-1, dp);
            return dp[n][amount] = min(a,b);
        }
        else
            return dp[n][amount] = unbdKnapSack(coins, amount, n-1, dp);
    }
};



*/