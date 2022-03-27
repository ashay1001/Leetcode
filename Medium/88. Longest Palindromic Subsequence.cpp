//Top Down approch
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        
        return calculate(dp, s ,0, s.length()-1);
    }
    
    int calculate(vector<vector<int>> &dp, string &s, int l, int r)
    {
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != 0) return dp[l][r];
        
        if(s[l] == s[r])
            return dp[l][r] = 2 + calculate(dp, s, l+1, r-1);
        
        return dp[l][r] = max(calculate(dp, s, l+1, r), calculate(dp, s, l, r-1));
        
    }
};