class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, ans, 0);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
    
    void solve(vector<int> &nums, set<vector<int>> &ans, int index)
    {
        if(index == nums.size())
        {
            ans.insert(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[i]);
        }
    }
};