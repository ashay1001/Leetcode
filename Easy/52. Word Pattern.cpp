class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream strcin(s);
        string str;
        vector<string> vs;
        
        while(strcin >> str) 
            vs.push_back(str);
        
        if (pattern.size() != vs.size()) 
            return false;
        
        map<string, char> mpStr;
        map<char, string> mpChar;
        
        for(int i=0; i<pattern.size(); i++)
        {
            if(mpChar.find(pattern[i]) == mpChar.end() && mpStr.find(vs[i]) == mpStr.end())
            {
                mpChar[pattern[i]] = vs[i];
                mpStr[vs[i]] = pattern[i];
                continue;
            }
            
            if(mpChar[pattern[i]] != vs[i])
                return false;
        }
        return true;
    }
};