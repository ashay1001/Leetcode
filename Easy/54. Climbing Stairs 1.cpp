class Solution {
public:
    int climbStairs(int n) {
        
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return climb(n, dp);
    }
    
    int climb(int n, int dp[])
    {
        if(n < 2) return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int a = climb(n-1, dp);
        int b = climb(n-2, dp);
        return dp[n] = a+b;
    }
};