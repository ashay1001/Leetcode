//backtracking approch
class Solution {
public:
    unordered_map<int, bool> mp;
    unordered_set<string> stringSet;
    
    bool wordBreak(string s, vector<string>& wordDict) {
         
        for(auto str : wordDict)
            stringSet.insert(str);
        
        return checkPartition(s, 0);
    }
    
    bool checkPartition(string s, int pos)
    {
        if(pos == s.length()) return true;
        if(mp.find(pos) != mp.end()) return mp[pos];
        
        for(int i=pos; i<s.length(); i++)
        {
            if(stringSet.find(s.substr(pos, i-pos+1)) != stringSet.end() and checkPartition(s, i+1))
                return mp[pos] = true;
        }
        return mp[pos] = false;
    }
};