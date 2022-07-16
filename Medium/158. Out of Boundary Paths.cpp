class Solution {
public:
    int MOD = 1000000007;
    int findPaths(int m, int n, int N, int startRow, int startColumn) {
        // 3D vector
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return solve(m, n, N, startRow, startColumn, dp);
    }
    
    int solve(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(i==m or i<0 or j==n or j<0) return 1;
        if(N == 0) return 0;
        if(dp[i][j][N] != -1) return dp[i][j][N];
        
        dp[i][j][N] = ((solve(m, n, N-1, i-1, j, dp) + solve(m, n, N-1, i+1, j, dp)) % MOD + 
                      (solve(m, n, N-1, i, j-1, dp) + solve(m, n, N-1, i, j+1, dp)) % MOD) % MOD;
        
        return dp[i][j][N];
    }
};

/*
    Time Complexity without memoization: O(4^N)
    Time Complexity with memoization: O(m x n x N)

*/