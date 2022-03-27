//Bottom-up approch (important)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        if(s.empty()) return 0;
        int n = s.size();
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        
        for(int k=1; k<n; k++)
        {
            for(int i=0; i<n-k; i++)
            {
                int j = i + k;
                
                // if there are only two chars
                if(j - i + 1 == 2)
                    dp[i][j] = 1 + (s[i] == s[j]);
                else
                {
                    if(s[i] == s[j])
                        dp[i][j] = 2 + dp[i+1][j-1];
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};