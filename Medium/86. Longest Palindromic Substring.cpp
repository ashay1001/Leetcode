class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        
        int i = 0, j = 0;
        int n = s.size();
        //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][i]=true;
            
            if(i == n-1) break;
            
            dp[i][i+1] = (s[i]==s[i+1]);
        }
        //dp 
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);     
            }
        }
        //get maxstr result
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j]==true and j-i+1>max)
                {
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};