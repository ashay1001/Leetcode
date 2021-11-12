class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) {return res;}
        sort(nums.begin(), nums.end());
        
        //fix one element and find two sum in sorted array using two pointer
        //approch
        for(int i=0; i<nums.size()-2; i++)
        {
            //to skip duplicate nums[i]
            if(i>0 && (nums[i]==nums[i-1]))
                continue;
            
            int start = i+1, end = nums.size()-1, target = -nums[i];
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                
                if(sum < target)
                    start++;
                else if(sum > target)
                    end--;
                else
                {
                    vector<int> v = {nums[i], nums[start], nums[end]};
                    res.push_back(v);
                    
                    //to skip duplicate for same nums[i]
                    while(start<end && nums[start]==nums[start+1]) start++; 
                    while(start<end && nums[end]==nums[end-1]) end--;
                    
                    start++;
                    end--;
                }
            }
        }
        return res;
    }
};

//[-4,-1,-1,0,1,2]