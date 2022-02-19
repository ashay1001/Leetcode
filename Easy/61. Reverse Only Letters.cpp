class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int start = 0, end = s.length();
        
        while(start < end)
        {
            if(isalpha(s[start]) && isalpha(s[end]))
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            
            if(!isalpha(s[start]))
                start++;
            if(!isalpha(s[end]))
                end--;
        }
        
        return s;
    }
};