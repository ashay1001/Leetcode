/*
    We can consider this 2D matrix as sorted list. If we have m * n matrix then:
      2D matrix[p][q] to 1D array => arr[p*n + q]
      1D array arr[x] to m * n matrix => matrix[x/n][x % n]
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col = matrix[0].size();
        int start = 0, end = row * col -1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            
            if(matrix[mid/col][mid%col] == target) {return true;}
            
            if(matrix[mid/col][mid%col] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};