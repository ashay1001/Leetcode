class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), total = 0, count = 0, minutes = 0;
        queue<pair<int, int>> q;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    total++;
                if(grid[i][j] == 2)
                {
                    total++; q.push({i, j});
                }
            }
        }
        
        while(!q.empty())
        {
            int k = q.size();
            count += k;
            while(k--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()) minutes++;
        }
        return count == total ? minutes : -1;
    }
};