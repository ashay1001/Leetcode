class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size(), m = text2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        return dp[n][m];
    }
};

/*
Recursive:

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return LCS(text1, text2, n, m, dp);
    }
    
    int LCS(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
    {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1, dp);
        else
            return dp[n][m] = max(LCS(s1,s2, n-1, m, dp), LCS(s1, s2, n, m-1, dp));
    }
};

*/