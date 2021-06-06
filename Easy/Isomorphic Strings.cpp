class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        char arr1[256] = {0};
        char arr2[256] = {0};
        
        for(int i=0; i<s.length(); i++)
        {
            if(arr1[s[i]] != arr2[t[i]])
                return false;
            
            arr1[s[i]] = i+1;
            arr2[t[i]] = i+1;
        }
        return true;
    }
};