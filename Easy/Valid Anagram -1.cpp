#include<bits/stdc++.h>
using namespace std;

void check()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

bool isAnagram(string s, string t) 
{
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> mp;
        unordered_map<char, int> :: iterator it;
        
        for(int i=0;i<s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
                mp[s[i]]++;
            
            else
                mp[s[i]] = 1;
        }
        
        for(int i=0;i<s.length(); i++)
        {
            if(mp.find(t[i]) != mp.end())
            {
                mp[t[i]]--;
            }
        }
        
        it = mp.begin();
        while(it != mp.end())
        {
            if(it->second != 0)
                return false;
            it++;
        }
        return true;
}


int main()
{
    check();
	isAnagram("ashay", "ashay")?cout<<"TRUE":cout<<"FALSE";
	return 0;
}