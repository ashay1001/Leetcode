class Solution {
public:
    bool canJump(vector<int>& nums) {
    
        int max_reach = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(i <= max_reach)
                max_reach = max(max_reach, i+nums[i]);
        }
        if(max_reach >= nums.size()-1)
            return true;
        else
            return false;
    }
};