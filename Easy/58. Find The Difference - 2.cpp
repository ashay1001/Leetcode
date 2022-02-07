class Solution {
public:
    char findTheDifference(string s, string t) {
     
        int result = 0;
        
        for(int i=0; i<s.size(); i++)
            result += t[i]-s[i];
        
        return result + t[t.size()-1];
    }
};