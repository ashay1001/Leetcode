class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
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
        while(index+1 < nums.size() and nums[index] == nums[index+1])
            index++;
        solve(nums, temp, ans, index+1);
    }
};

//using for loop
/*
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, temp, ans, 0);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
    {
        ans.push_back(temp);
        
        for(int i=index; i<nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1]) 
                continue;
            
            temp.push_back(nums[i]);
            solve(nums, temp, ans, i+1);
            temp.pop_back();
        }
    }
};
*/

//using set
/*
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        solve(nums, temp, ans, 0);
        
        for (auto it = ans.begin(); it != ans.end(); it++)
            result.push_back( * it);
        
        return result;
    }
    
    void solve(vector<int> &nums, vector<int> &temp, set<vector<int>> &ans, int index)
    {
        if(index == nums.size())
        {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, temp, ans, index+1);
        temp.pop_back();
        solve(nums, temp, ans, index+1);
    }
};
*/