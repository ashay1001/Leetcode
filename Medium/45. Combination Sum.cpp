class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> ans;
        //sort(candidates.begin(), candidates.end());
        genComb(0, ans, result, target, candidates);
        return result;
    }
    
    void genComb(int i, vector<int> &ans, vector<vector<int>> &result, int target, vector<int> &candidates)
    {
        if(target == 0)
        {
            result.push_back(ans);
            return;
        }
        
        if(i>=candidates.size() || target < 0)
            return;
        
        ans.push_back(candidates[i]);
        genComb(i, ans, result, target-candidates[i], candidates);
        ans.pop_back();
        genComb(++i, ans, result, target, candidates);
    }
};