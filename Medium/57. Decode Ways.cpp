class Solution {
public:
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        vector<int> dp(s.length()+1, -1);
        return dfs(s, 0, dp);
    }
    
    int dfs(string s, int index, vector<int> &dp)
    {
        if(dp[index] != -1) return dp[index];
        
        if(s[index] == '0') return dp[index] = 0;
        
        if(index == s.length()) return dp[index] = 1;
        
        int res = dfs(s, index+1, dp);
        
        if(index < s.length()-1 && (s[index] == '1' or (s[index] == '2' and s[index+1] <='6')))
            res += dfs(s, index+2, dp);
        
        return dp[index] = res;
    }
};