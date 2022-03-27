class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int index = 0, count = 0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(index % 2 == 0)
            {
                if(nums[i] == nums[i+1])
                {
                    count++;
                    continue;
                }
            }
            index++;
        }
        if(index % 2 == 0)
            count++;
        return count;
    }
};