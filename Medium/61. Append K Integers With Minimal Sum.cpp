class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        long long sum = 0;
        long long prev = 0;
        int i = 0;
        
        while(k>0 && i<nums.size())
        {
            int length = nums[i]-prev-1;
            
            if(k < length)
                length = k;
            
            if(length > 0)
            {
                long long start = prev;
                long long end = start + length;
                long long res = end*(end+1)/2 - start*(start+1)/2;
                sum += res;
                k -= length;
            }
            prev = nums[i];
            i++;
        }
        if(k > 0)
        {
            long long start = prev;
            long long end = start + k;
            long long res = end*(end+1)/2 - start*(start+1)/2;
            sum += res;
        }
        return sum;
    }
};