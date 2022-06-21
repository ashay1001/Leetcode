class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, temp, ans, 0);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(nums, temp, ans, index+1);
        temp.pop_back();
        solve(nums, temp, ans, index+1);
    }
};

/* //using for loop

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, temp, ans, 0);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
    {
        ans.push_back(temp);
        
        for(int i=index; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            solve(nums, temp, ans, i+1);
            temp.pop_back();
        }
    }
};

*/