class Solution {
public:
    bool static comp(int a, int b)
    {
        return a > b;
    }
    int minDeletions(string s) {
        
        vector<int> v(26, 0);
        unordered_set<int> st;
        
        int count = 0;
        
        for(int i=0; i<s.size(); i++)
            v[s[i]-'a']++;
        
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<26; i++)
        {
            while(v[i] != 0 and st.find(v[i]) != st.end())
            {
                v[i]--, count++;
            }
            st.insert(v[i]);
        }
        return count;
    }
};