class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(200, vector<int>(200,-1));
        return solve(0, 0, triangle, 0, dp);
    }
    
    int solve(int i, int rows, vector<vector<int>> &t, int sum, vector<vector<int>> &dp)
    {
        if(rows >= t.size()) return 0;
        
        if(dp[rows][i] != -1) return dp[rows][i];
        
        sum += t[rows][i] + min(solve(i, rows+1, t, sum, dp), solve(i+1, rows+1, t, sum, dp));
        return dp[rows][i] = sum;
    }
};