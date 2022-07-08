class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(s1, s2, s3, "", 0, 0, 0, dp);
    }
    
    bool solve(string &s1, string &s2, string &s3, string ans, int i, int j, int k, vector<vector<int>> &dp)
    {
        if(k == s3.size() and ans == s3) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool first = false, second = false;
        
        if(i<s1.size() and s1[i] == s3[k])
            first = solve(s1, s2, s3, ans+s1[i], i+1, j, k+1, dp);
        
        if(j<s2.size() and s2[j] == s3[k])
            second = solve(s1, s2, s3, ans+s2[j], i, j+1, k+1, dp);
        
        return dp[i][j] = first || second;
    }
};