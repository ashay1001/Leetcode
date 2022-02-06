class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        unordered_map<int, int> mp;
        int sum = 0, maxlen = 0;      
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1:1;
            
            if(sum == 0)
                maxlen = max(maxlen, i+1);
            
            else if(mp.find(sum) != mp.end())
                maxlen = max(maxlen, i-mp[sum]);
            
            else
                mp[sum] = i;
        }
        return maxlen;
    }
};