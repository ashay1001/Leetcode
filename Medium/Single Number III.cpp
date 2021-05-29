class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> map;
        unordered_map<int, int> :: iterator it;
        
        for(int i=0; i<nums.size(); i++)
        {
            it = map.find(nums[i]);
            if(it != map.end())
            {
                it->second++;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }
        
        vector<int> v;
        
        for(it=map.begin(); it != map.end(); it++)
        {
            if(it->second < 2)
                v.push_back(it->first);
        }
        return v;
        
    }
};