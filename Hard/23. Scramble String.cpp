class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool isScramble(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
    
        if(m!=n) return false;
        if(m==0 && n==0) return true;
        
        return solve(s1,s2);
    }
    
    
    bool solve(string s,string t)
    {
        int n=s.length();
        
        if(s.compare(t)==0) return true;
        if(n<=1) return false;
        
        bool scramble=false; //initialy
        
        string key=s+" "+t;
        
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        
        for(int i=1;i<=n-1;i++)
        {
            bool cond1 = solve(s.substr(0,i),t.substr(n-i,i)) &&
                         solve(s.substr(i,n-i),t.substr(0,n-i));  //swapped parts
           
            //not swapped
            bool cond2 = solve(s.substr(0,i),t.substr(0,i)) &&
                         solve(s.substr(i,n-i),t.substr(i,n-i));
           
            if(cond1 || cond2)
            {
                scramble=true;
                break;
            }
        }
        return mp[key]=scramble;
    }
};