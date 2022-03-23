class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> dp(501, 0);
        if(nums.size()%2 != 0) return false;
        for(int i=0; i<nums.size(); i++)
        {
            dp[nums[i]]++;
            
        }
        for(int i=0; i<dp.size(); i++)
        {
            if(dp[i] % 2 != 0) return false;
            
        }
        return true;
    }
};