//using LCS
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return LCS(s, s2);
    }
    
    int LCS(string &s1, string &s2)
	{
	    int n = s1.size(), m = s2.size();
	    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	    
	    for(int i=1; i<n+1; i++)
	    {
	        for(int j=1; j<m+1; j++)
	        {
	            if(s1[i-1] == s2[j-1])
	                dp[i][j] = 1 + dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    return dp[n][m];
	}
};