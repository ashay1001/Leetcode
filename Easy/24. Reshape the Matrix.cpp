class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> new_mat(r, vector<int> (c,0));
        int row=0, col=0;
        
        if((m*n) != r*c) {return mat;}
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                new_mat[row][col] = mat[i][j];
                col++;
                if(col == c) 
                {
                    col = 0; row++;
                }
            }
        }
        return new_mat;
    }
};