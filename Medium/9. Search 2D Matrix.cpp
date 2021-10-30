class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = -1;
        for(int i=0; i<matrix.size()-1; i++)
        {
            if(target>=matrix[i][0] && target<matrix[i+1][0])
            {
                row = i;
                break;
            }
        }
        if(row == -1)
            row = matrix.size()-1;
        
        for(int i=0; i<matrix[0].size(); i++)
        {
            if(matrix[row][i] == target)
                return true;
        }
        return false;
    }
};