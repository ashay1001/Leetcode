class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.length() == 0) return true;
        if(s.length() == 0 and t.length() == 0) return true;
        if(t.length() == 0) return false;
        int start = 0;
        
        for(int i=0; i<t.length(); i++)
        {
            if(s[start] == t[i])
                start++;
            if(start == s.length())
                return true;
        }
        return false;
    }
};