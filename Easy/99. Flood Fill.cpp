class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(prev != color)
            solve(image, sr, sc, color, prev);
        return image;
    }
    
    void solve(vector<vector<int>> &image, int row, int col, int &color, int &prev)
    {
        if(row<0 or col<0 or row>=image.size() or col>=image[0].size() or image[row][col] == color or image[row][col] != prev)
            return;
       
        image[row][col] = color;
        solve(image, row, col+1, color, prev);
        solve(image, row, col-1, color, prev);
        solve(image, row+1, col, color, prev);
        solve(image, row-1, col, color, prev);
    }
};