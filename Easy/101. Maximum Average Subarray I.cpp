class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double sum = 0;
        int end = k, i;

        for(i=0; i<k; i++)
            sum += nums[i];
        ans = sum;
        i = 0;
        while(end < nums.size())
        {
            sum -= nums[i++];
            sum += nums[end++];
            ans = max(sum, ans);
        }
        return ans/k;
    }
};