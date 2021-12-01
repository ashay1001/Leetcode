class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxlen = 0;
        int count = 0;
        unordered_set<char> set_s;
        
        for(int i=0; i<s.length(); i++)
        {
            for(int j=i; j<s.length(); j++)
            {
                if(set_s.find(s[j]) == set_s.end())
                {
                    set_s.insert(s[j]);
                    count++;
                    maxlen = max(count, maxlen);
                }
                else
                {
                    count = 0;
                    set_s.clear();
                    break;
                }
            }
        }
        return maxlen;
    }
};