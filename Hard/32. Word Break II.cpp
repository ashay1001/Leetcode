class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> mp;
        unordered_set<string> stringSet;
        vector<string> ans;
        
        for(auto str : wordDict)
            stringSet.insert(str);
        
        for(int i=0;i<s.size();++i)
        {
            if(stringSet.find(s.substr(0,i+1)) != stringSet.end())
                solve(s, s.substr(0,i+1), i+1, ans, stringSet);
        }
        return ans;
    }
    
    void solve(string &s, string st, int pos, vector<string> &ans, unordered_set<string> &stringSet)
    {
        if(pos == s.size()){
            ans.push_back(st);
            return;
        }
        st += " ";
        for(int i=pos;i<s.size();++i){
            if(stringSet.find(s.substr(pos,i+1-pos)) != stringSet.end())
                solve(s, st+s.substr(pos,i+1-pos), i+1, ans, stringSet);
        }
    }
};
