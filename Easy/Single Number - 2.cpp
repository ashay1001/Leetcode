// 2*(a+b+c) - (a+a+b+b+c) = c

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        set<int> s;
        int setSum = 0;
        int numsSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
                setSum += nums[i];
            }
            numsSum += nums[i];
        }
        return 2*setSum - numsSum;
    }
};