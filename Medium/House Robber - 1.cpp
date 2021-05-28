// Top-down approch with memoization

class Solution {
public:
    vector<int> memo;
    
    int rob(vector<int>& nums) {
    
        memo.assign(nums.size(),-1);
        return robber(nums, nums.size()-1);
    }
    
    
    int robber(vector<int> &arr, int i)
    {
        if(i<0)
            return 0;
        
        if(memo[i]>-1)
            return memo[i];
        
        int result = max(arr[i] + robber(arr, i-2), robber(arr, i-1));
        memo[i] = result;
        return result;
    }
};