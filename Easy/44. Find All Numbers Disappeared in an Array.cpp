class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        /*
            we are going to negate those indexes whose corresponding values are present
            in an array. 
            Example: [4,3,2,7,8,2,3,1]
            as nums[0] => 4, we will mark 4-1 = 3 i.e 3rd index as -ve. Which represents that
             value 4 is present in an array.
        */
        for(int i=0; i<nums.size(); i++)
        {
            int value = abs(nums[i]) - 1;
            nums[value] = (nums[value] > 0) ? -nums[value] : nums[value];
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};