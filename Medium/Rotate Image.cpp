class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i; j<matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<matrix.size(); i++)
        {
            int l = 0, r = matrix[0].size()-1;
            while(l<r)
            {
                int t = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = t;
                l++;
                r--;
            }
        }
    }
};