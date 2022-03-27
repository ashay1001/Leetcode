class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>> res;
        vector<int> ans;
        for(int i=0; i<mat.size(); i++)
        {
            int count = 0;
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            res.push_back({count, i});
        }
        sort(res.begin(), res.end());
        
        for(int i=0; i<k; i++)
            ans.push_back(res[i][1]);
        
        return ans;
    }
};