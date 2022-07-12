class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        
        for(int i=0; i<k; i++)
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};