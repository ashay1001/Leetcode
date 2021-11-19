class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        /*
            we are going to use same approch that we usedd in
            "448. Find All Numbers Disappeared in an Array"
        */
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[abs(nums[i])-1] < 0)
                res.push_back(abs(nums[i]));
            
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        
        return res;
    }
};