class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", s2 = "";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != '#')
                s1 += s[i];
            else if(s1.length() > 0)
                s1.pop_back();
        }
        
        for(int i=0; i<t.length(); i++)
        {
            if(t[i] != '#')
                s2 += t[i];
            else if(s2.length() > 0)
                s2.pop_back();
        }
        
        return s1 == s2;
    }
};