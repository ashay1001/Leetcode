class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0, i=0, j=0;
        unordered_set<int> st;
        
        while(i<nums.size() and j<nums.size())
        {
            if(st.find(nums[j]) == st.end())
            {
                st.insert(nums[j]);
                sum += nums[j++];
                ans = max(ans, sum);
                //cout<<"in j ans = "<<ans<<" sum = "<<sum<<endl;
            }
            
            else
            {
                st.erase(nums[i]);
                sum -= nums[i++];
                //cout<<"in i ans = "<<ans<<" sum = "<<sum<<endl;
            }
        }
        return ans;
    }
};