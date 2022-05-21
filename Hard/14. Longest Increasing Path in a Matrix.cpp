class Solution 
{
    public:
    int dfs(vector<vector<int>> &matrix,int i,int j,int parent,vector<vector<int>> &dp)
    {
        if(i>=matrix.size() || j>=matrix[0].size() || i<0 || j<0 || matrix[i][j]<=parent)
        {
            return 0;
        }
    
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
    
        int down=dfs(matrix,i+1,j,matrix[i][j],dp);
        int up=dfs(matrix,i-1,j,matrix[i][j],dp);
        int right=dfs(matrix,i,j+1,matrix[i][j],dp);
        int left=dfs(matrix,i,j-1,matrix[i][j],dp);
        
        dp[i][j]=1+max(max(left,right),max(up,down));
        
        return dp[i][j];
    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=dfs(matrix,i,j,-1,dp);
            }
        }
    
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};