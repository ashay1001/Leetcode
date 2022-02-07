class Solution {
public:
    char findTheDifference(string s, string t) {
     
        int arr[26];
        memset(arr, 0, sizeof(arr));
        char ch;
        
        for(int i=0; i<s.length(); i++)
            arr[s[i] - 'a']++;
        
        for(int i=0; i<t.length(); i++)
            arr[t[i] - 'a']--;
        
        for(int i=0; i<26; i++)
            if(arr[i] != 0)
               ch = 'a' + i;
        
        return ch;
    }
};