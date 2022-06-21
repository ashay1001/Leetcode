class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
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
        solve(nums, temp, ans, index+1, target-nums[index]);
        temp.pop_back();
        while(index+1 < nums.size() and nums[index] == nums[index+1])
            index++;
        solve(nums, temp, ans, index+1, target);
    }
};