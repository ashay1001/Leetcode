// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
        
//         if(nums.size() < 3) return 0;
//         vector<int> dp(nums.size(), 0);
//         int res = 0;
//         int diff  = nums[1]-nums[0];
        
//         if(nums[2]-nums[1] == diff)
//         {
//             dp[1] = 1;
//             res = 1;
//         }
//         diff = nums[2]-nums[1];
//         for(int i=2; i<nums.size()-1; i++)
//         {
//             if(nums[i+1] - nums[i] == diff)
//             {
//                 dp[i] = dp[i-1] + 1;
//                 res += dp[i];
//             }
//             else
//                 diff = nums[i+1] - nums[i];
//         }
//         return res;
//     }
// };

// we are only using previous value from dp vector. Hence single variable can be used. 

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3) return 0;
        int dp = 0;
        int res = 0;
        int diff  = nums[1]-nums[0];
        
        if(nums[2]-nums[1] == diff)
        {
            dp = 1;
            res = 1;
        }
        diff = nums[2]-nums[1];
        for(int i=2; i<nums.size()-1; i++)
        {
            if(nums[i+1] - nums[i] == diff)
            {
                dp += 1;
                res += dp;
            }
            else
            {
                diff = nums[i+1] - nums[i];
                dp = 0;       
            }
        }
        return res;
    }
};