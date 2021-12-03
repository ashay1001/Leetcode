class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int product = 1;
        int result = INT_MIN;
        /*
            First we will iterate in forward direction 
            and find the max value. Whenver 0 comes set product again to 1.
        */
        for(int i=0; i<nums.size(); i++)
        {
            product = product * nums[i];
            result = max(result, product);
            if(product == 0)
            {
                product = 1;
            }
        }
        product = 1;
        //Now iterate in reverse direction and check with maximum obtained 
        //in first iteration
        for(int i=nums.size()-1; i>=0; i--)
        {
            product = product * nums[i];
            result = max(result, product);
            if(product == 0)
            {
                product = 1;
            }
        }
        
        return result;
    }
};