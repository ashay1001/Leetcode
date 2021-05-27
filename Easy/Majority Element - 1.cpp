class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map;
        int max = 0,ele;
        
        for(int i=0; i<nums.size(); i++)
        {
            unordered_map<int, int> :: iterator it = map.find(nums[i]); 
            if(it != map.end())
            {
                it->second++;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }
        
        unordered_map<int, int> :: iterator it = map.begin();
        while(it != map.end())
        {
            if(it->second>max)
            {
                max=it->second;
                ele=it->first;
            }
            it++;
        }
        return ele;
    }
};