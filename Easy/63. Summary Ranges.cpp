class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size() == 0) return {};
        
        vector<string> ans;      
        for(int i=0; i<nums.size(); )
        {
            int start = i, end = i;
            while(end < nums.size()-1 && nums[end+1] == nums[end] + 1)
                end++;
            
            if(end == start)
                ans.push_back(to_string(nums[start]));
            else
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            i = end + 1;                                                                   
        }
        return ans;
    }
};