class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    mark_island(grid, i, j, m, n);
                    ans += 1;
                }
            }
        }
        return ans;
    }
    
    void mark_island(vector<vector<char>> &grid, int x, int y, int &m, int &n)
    {
        if(x<0 or x>=m or y<0 or y>=n or grid[x][y] != '1')
            return;
        
        grid[x][y] = 'V';
        
        mark_island(grid, x+1, y, m, n);
        mark_island(grid, x, y+1, m, n);
        mark_island(grid, x-1, y, m, n);
        mark_island(grid, x, y-1, m, n);
    }
};