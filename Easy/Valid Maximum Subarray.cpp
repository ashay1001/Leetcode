class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    vector<int> arr = nums;
    arr[0] = nums[0];
    int maximum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            arr[i] = nums[i] + (arr[i-1]>0 ? arr[i-1] : 0);
            maximum = max(arr[i],maximum);
            
        }
        return maximum;
    }
};