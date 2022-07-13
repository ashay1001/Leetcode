class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        stack<int> st;
        int n = nums2.size();
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and st.top() < nums2[i])
                st.pop();
           
            if(st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int num : nums1)
            ans.push_back(mp[num]);
        
        return ans;
    }
};