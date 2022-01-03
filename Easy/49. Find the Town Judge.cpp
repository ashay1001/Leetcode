class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n+1);
        
        for(int i=0; i<trust.size(); i++)
        {
            ans[trust[i][1]]++;
            ans[trust[i][0]]--;
        }
        for(int i=1; i<=n; i++)
        {
            if(ans[i] == n-1)
                return i;            
        }
        return -1;
    }
};