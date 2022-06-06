class Solution {
public:
    int minCut(string s) {
        
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return solve(s, 0, N-1, dp);
    }
    
    int solve(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s, i, j) || i >= j) return 0;
        
        int minimum = INT_MAX;
        
        for(int k=i; k<=j-1; k++)
        {
            //int temp = solve(s, i, k, dp) + solve(s, k+1, j, dp) + 1;
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                minimum = min (minimum, temp);
            }
        }
        return dp[i][j] = minimum;
    }
    
    bool isPalindrome(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
};