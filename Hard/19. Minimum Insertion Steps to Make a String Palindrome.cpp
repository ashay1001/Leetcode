class Solution {
public:
    int minInsertions(string s) {
     
        string s2 = s; 
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return n - dp[n][n];
    }
};

/*
Same as minimum number of deletions to make string palindrom.
Because we can make s string palindrom either by deleting extra letters or by adding same letters.

Ex: s = heep

Either delete h,p of make hpeeph....both ways ans is 2.
*/