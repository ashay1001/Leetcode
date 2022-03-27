class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1;
        set<int> s2;
        vector<int> ans1, ans2;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        for(int i=0; i<n1; i++)
            s1.insert(nums1[i]);
        
        for(int i=0; i<n2; i++)
            s2.insert(nums2[i]);
        
        for (auto it = s1.begin(); it != s1.end(); it++)
        {
            if(s2.find(*it) == s2.end())
                ans1.push_back(*it);
        }
        
        for (auto it = s2.begin(); it != s2.end(); it++)
        {
            if(s1.find(*it) == s1.end())
                ans2.push_back(*it);
        }
        
        return {ans1, ans2};
    }
};