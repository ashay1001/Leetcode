class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int len = 0, counter = 0, product = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                counter = 0;
                product = 1;
                continue;
            }
            else if(nums[i] > 0)
                product *= 1;
            else
                product *= -1;
            
            counter++;
            if(product > 0)
                len = max(len, counter);
        }
        counter = 0, product = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] == 0)
            {
                counter = 0;
                product = 1;
                continue;
            }
            else if(nums[i] > 0)
                product *= 1;
            else
                product *= -1;
            
            counter++;
            if(product > 0)
                len = max(len, counter);
        }
        return len;
    }
};