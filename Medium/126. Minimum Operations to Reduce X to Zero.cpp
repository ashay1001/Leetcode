class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;     //sum zero present at -1 index;
        for(int num : nums)
            total += num;
        
        int target = total - x;
        int prefixSum = 0, maxSubLen = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            prefixSum += nums[i];
            mp[prefixSum] = i;
            
            if(mp.find(prefixSum - target) != mp.end())
            {
                int subLen = i - mp[prefixSum-target];
                maxSubLen = max(maxSubLen, subLen);
            }
        }
        
        return maxSubLen == -1 ? -1 : nums.size()-maxSubLen;
    }
};