class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int count = 0;
        
        for(auto num : nums)
            mp[num]++;
        
        for(auto num : mp)
        {
            if(k == 0)
            {
                if(num.second > 1)
                    count++;
            }
            else
            {
                if(mp.find(num.first + k) != mp.end())
                    count++;
            }
        }
        return count;
    }
};