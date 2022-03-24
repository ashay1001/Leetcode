class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j];
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int r1 = max(0, i-k), c1 = max(0, j-k);
                int r2 = min(m, i + k + 1), c2 = min(n, j + k + 1);
                res[i][j] = dp[r2][c2] - dp[r2][c1] - dp[r1][c2] + dp[r1][c1];
            }
        }
        return res;
    }
};