class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        return (solve(0, h, horizontalCuts) * solve(0, w, verticalCuts)) % 1000000007;
    }
    
    long int solve(int start, int end, vector<int> cuts)
    {
        int ans = 0;
        
        for(int i=0; i<cuts.size(); i++)
        {
            ans = max(ans, cuts[i]-start);  //start initially contains 0
            start = cuts[i];
        }
        ans = max(ans, end-start);  // To handle last portion
        return ans;
    }
};