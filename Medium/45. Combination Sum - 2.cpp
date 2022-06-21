class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, temp, ans, 0, target);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(index == nums.size() or target<0)
            return;
        
        temp.push_back(nums[index]);
        solve(nums, temp, ans, index, target-nums[index]);
        temp.pop_back();
        solve(nums, temp, ans, index+1, target);
    }
};