class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        
        if(og[0][0] == 1) return 0;
        vector<vector<int>> dp(og.size(), vector<int>(og[0].size(), 1));
        
        int row = og.size(), col = og[0].size();
        int flag = 0;
        for(int i=0; i<row; i++)
        {
           if(og[i][0] == 1 || flag == 1)
           {
               dp[i][0] = 0; flag = 1;
           }
        }
        flag = 0;
        for(int i=0; i<col; i++)
        {
           if(og[0][i] == 1 || flag == 1)
           {
               dp[0][i] = 0; flag = 1;
           }
        }
        for(int i=1; i<row; i++)
        {
            for(int j=1; j<col; j++)
            {
                if(og[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];   
                }
            }
        }
        return dp[row-1][col-1];
    }
};