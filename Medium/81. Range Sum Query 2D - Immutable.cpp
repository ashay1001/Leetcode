class NumMatrix {
private:
    vector<vector<int>> res;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        res = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                res[i+1][j+1] = res[i+1][j] + res[i][j+1] - res[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
     
        return res[row2+1][col2+1] - res[row2+1][col1] - res[row1][col2+1] + res[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */