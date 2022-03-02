class Solution {
public:
    int trap(vector<int>& height) {
     
        int n = height.size();
        int dp[2][n];
        
        dp[0][0] = 0;
        dp[1][n-1] = 0;
        int maxHeight = height[0];
        int res = 0;
        
        for(int i=1; i<n; i++)
        {
            dp[0][i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        maxHeight = height[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            dp[1][i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(height[i] < dp[0][i] && height[i] < dp[1][i])
                res += min(dp[0][i], dp[1][i]) - height[i];
        }
        
        return res;
    }
};