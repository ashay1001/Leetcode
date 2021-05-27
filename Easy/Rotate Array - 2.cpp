class Solution {
public:
    
    void reverse(vector<int> &nums, int i, int j)
    {
        while(i < j)
        {
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
     
        reverse(nums,0,nums.size()-1);
        k = k % nums.size();
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};