class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        unordered_set<int> row;
        unordered_set<int> col;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i); col.insert(j);
                }
            }
        }
        
        for(auto itr = row.begin(); itr != row.end(); itr++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                matrix[*itr][j] = 0;
            }
        }
        
        for(auto itr = col.begin(); itr != col.end(); itr++)
        {
            for(int i=0; i<matrix.size(); i++)
            {
                matrix[i][*itr] = 0;
            }
        }
    }
};