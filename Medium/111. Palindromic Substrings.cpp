class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=n-i; j++)
            {
                string str = s.substr(i,j);
                if(check(str))
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    bool check(string &s)
    {
        int start = 0;
        int end = s.size()-1;
        while(start <= end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

// TC: O(n^3)