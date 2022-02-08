/*

    1. calculate maxmimum subarray using kadanes algorithm. Lets assume this value as 'x'.
    2. now to calculate min subarray using kadanes algo, invert all the values of array and find max subarray. Lets assue this result as 'y'.
    3. calculate array sum.
    4. wrap sum = array sum - ( - y ) ==> wrap sum = array sum + y.
    5. return max(x , y)

    Note: if wrapsum == 0, it means all the values in the array are negative or there exist one 
    negative subarray such that its value is equal to array sum. 
    Hence in both the cases we can safely return the maximum subarray calculated in 1st step. 
    Because when all the values are negative, kadanes algo gives the smallest negative value.

*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     
        int maxsub = kadane(nums);
        int arrsum = 0, wrapsum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            arrsum += nums[i];
            nums[i] = -nums[i];
        }
        
        wrapsum = arrsum + kadane(nums);
        
        if(wrapsum == 0)
            return maxsub;
        
        return max(maxsub, wrapsum);
    }
    
    int kadane(vector<int> &nums)
    {
        int currsum = 0, maxsum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            currsum += nums[i];
            maxsum = max(currsum, maxsum);
            if(currsum < 0)
                currsum = 0;
        }
        return maxsum;
    }
};