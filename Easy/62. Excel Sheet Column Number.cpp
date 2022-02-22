class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long result = 0;
        
        int n = columnTitle.length();
        
        for(int i=0; i<n; i++)
        {
            result = result * 26 + (columnTitle[i] - 'A' + 1);
        }
        return result;
    }
};