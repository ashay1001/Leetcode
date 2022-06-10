class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        int max_streak = 0;
        
        for(int num : nums)
            st.insert(num);
        
        for(int num : st)
        {
            if(st.find(num-1) == st.end())     // i.e check if num is 1st element of sequence
            {
                int curr_ele = num;
                int streak = 1;
                
                while(st.find(curr_ele+1) != st.end())
                {
                    curr_ele += 1;
                    streak += 1;
                }
                max_streak = max(max_streak, streak);
            }
        }
        return max_streak;
    }
};