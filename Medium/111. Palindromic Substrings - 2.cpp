class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        for(int i=0; i<s.size(); i++)
        {
            count += check(s, i, i);
            count += check(s, i, i+1);
        }
        return count;
    }
    
    int check(string &s, int left, int right)
    {
        int count = 0;
        while(left>=0 and right < s.size() and s[left] == s[right])
        {
            count += 1; left--; right++;
        }
        return count;
    }
};

//TC: O(n^2)