class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1));
        
        //base condition
        for(int i=0; i<amount+1; i++)
            dp[0][i] = 0;
        for(int i=0; i<coins.size()+1; i++)
            dp[i][0] = 1;   //No. ways in which we can make amount '0' considering 'i' coins
        
        for(int i=1; i<coins.size()+1; i++)
        {
            for(int j=0; j<amount+1; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; //similar to count of subsets but in unbounded way
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};


/*
Recursive:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return unbdKnapSack(amount, coins, n, dp);
    }
    
    int unbdKnapSack(int amount, vector<int> &coins, int n, vector<vector<int>> &dp)
    {
        if(n == 0) return 0;
        if(amount == 0) return 1;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        
        if(coins[n-1] <= amount)
        {
            dp[n][amount] = unbdKnapSack(amount-coins[n-1], coins, n, dp) + unbdKnapSack(amount, coins, n-1, dp);
            return dp[n][amount];
        }
        else
            return dp[n][amount] = unbdKnapSack(amount, coins, n-1, dp);
    }
};

*/