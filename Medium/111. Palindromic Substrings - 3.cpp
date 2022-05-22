class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = n;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        
        for(int i=0; i<n-1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1; count++;
            }
        }
        
        for(int k=2; k<n; k++)
        {
            for(int i=0; i<n-k; i++)
            {
                int j = k + i;
                if(dp[i+1][j-1] == 1 and s[i] == s[j])
                {
                    dp[i][j] = 1; count++;
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        return count;
    }
};