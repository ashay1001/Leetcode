class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> ans;
        getSum(result, ans, k, n, 1);
        return result;
    }
    
    void getSum(vector<vector<int>> &result, vector<int> &ans, int k, int n, int num)
    {
        if(k == 0)
        {
            if(n == 0)
                result.push_back(ans);
            return;
        }
        
        if(num > 9) return;
        
        ans.push_back(num);
        getSum(result, ans, k-1, n-num, num+1);
        ans.pop_back();
        getSum(result, ans, k, n, num+1);
    }
    
};