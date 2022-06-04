class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        longestCommonSubsequence(str1, str2, dp, n, m);
        string lcs = printLCS(dp, str1, str2, n, m);
        
        int i = 0, j = 0;
        string res = "";
        
        for (char c : lcs) 
        {
            while (str1[i] != c)
                res += str1[i++];
            
            while (str2[j] != c)
                res += str2[j++];
            
            res += c, i++, j++;
        }
        return res + str1.substr(i) + str2.substr(j);
    }
    
    void longestCommonSubsequence(string &text1, string &text2, vector<vector<int>> &dp, int n, int m) {
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
    }
    
    string printLCS(vector<vector<int>> &dp, string &s1, string &s2, int n, int m)
    {
        string result = "";
        int i = n, j = m;
        
        while(i>0 && j>0)
        {
            if(s1[i-1] == s2[j-1])
            {
                result.push_back(s1[i-1]); i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};